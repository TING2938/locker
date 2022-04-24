import numpy as np
import matplotlib.pyplot as plt

# Gamma = 0.618
# k2 = 0.187572
# k3 = 0.05  # 0.1s/step, k3越大，温度下降越快


class Memory:
    def __init__(self, size_Nx_time=50):
        self.CPU_Temp_time = [0]
        self.CPU_Temp = [-128]
        self.Nx_time = []
        self.Nx = []
        self.FanPwr = []
        self.CPU_Pwr = []
        self.CPU_Temp_Point = []
        self.size_cpu_time = 5 * size_Nx_time
        self.size_Nx_time = size_Nx_time

    def checkSize(self):
        if len(self.CPU_Temp_time) > self.size_cpu_time:
            self.CPU_Temp_time = self.CPU_Temp_time[(-self.size_cpu_time):]
            self.CPU_Temp = self.CPU_Temp[(-self.size_cpu_time):]
        if len(self.Nx_time) > self.size_Nx_time:
            self.Nx_time = self.Nx_time[(-self.size_Nx_time):]
            self.Nx = self.Nx[(-self.size_Nx_time):]
            self.FanPwr = self.FanPwr[(-self.size_Nx_time):]
            self.CPU_Temp_Point = self.CPU_Temp_Point[(-self.size_Nx_time):]
            self.CPU_Pwr = self.CPU_Pwr[(-self.size_Nx_time):]


def getNextT(T0, P, T_env, u, k2=0.187572, k3=0.05, Gamma=0.618):
    T1 = T0 + k3 * (P - k2 * u**Gamma * (T0 - T_env))
    return T1


class FanENV:
    def __init__(self):
        self.FanU_slotU_params = np.array([[1, 0, 0, 0, 0],
                                           [1, 0, 0, 0, 0],
                                           [1, 0, 0, 0, 0],
                                           [0.4, 0.6, 0, 0, 0],
                                           [0, 1, 0.1, 0, 0],
                                           [0, 0.1, 1, 0, 0],
                                           [0, 0, 0.9, 0.1, 0],
                                           [0, 0, 0, 1, 0],
                                           [0, 0, 0, 0.4, 0.5],
                                           [0, 0, 0, 0, 1]])
        self.FanNx = np.zeros(5)
        self.FanPwr = np.zeros(3)
        self.SensorTemp = np.zeros((24, 4))
        self.SensorParams = np.zeros((24, 4), dtype=object)
        self.BrdPwr = np.zeros(24)
        self.EnvTemp = 32
        self.SystemPwr = 0

        self.SensorTemp.fill(-128)
        self.SensorParams.fill(None)
        self.SensorParams[0, 0] = [0.187572, 0.05, 0.718]
        self.SensorParams[2, 0] = [0.187572, 0.05, 0.618]
        self.SensorParams[2, 2] = [0.187572, 0.05, 0.618]
        self.SensorParams[3, 0] = [0.187572, 0.05, 0.618]
        self.SensorParams[3, 2] = [0.187572, 0.05, 0.618]
        self.SensorParams[5, 0] = [0.187572, 0.05, 0.618]
        self.SensorParams[5, 2] = [0.187572, 0.05, 0.618]
        self.SensorParams[7, 0] = [0.187572, 0.05, 0.618]
        self.SensorParams[7, 0] = [0.187572, 0.05, 0.618]
        self.SensorParams[9, 0] = [0.187572, 0.05, 0.618]
        self.SensorParams[9, 0] = [0.187572, 0.05, 0.618]
        self.SensorParams[10, 0] = [0.187572, 0.05, 0.618]
        self.SensorParams[10, 0] = [0.187572, 0.05, 0.618]

        INVALID_VALUE = 4294967295
        self.boardType = np.array([0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, INVALID_VALUE, INVALID_VALUE,
                                   INVALID_VALUE, INVALID_VALUE, INVALID_VALUE, INVALID_VALUE, INVALID_VALUE, INVALID_VALUE])

        self.brdFanID = np.zeros((24, 2))
        self.brdFanID.fill(INVALID_VALUE)
        self.brdFanID[0, :] = np.array([1, INVALID_VALUE])
        self.brdFanID[1, :] = np.array([1, INVALID_VALUE])
        self.brdFanID[2, :] = np.array([1, INVALID_VALUE])
        self.brdFanID[3, :] = np.array([1, 2])
        self.brdFanID[4, :] = np.array([2, 3])
        self.brdFanID[5, :] = np.array([2, 3])
        self.brdFanID[6, :] = np.array([3, 4])
        self.brdFanID[7, :] = np.array([4, INVALID_VALUE])
        self.brdFanID[8, :] = np.array([4, 5])
        self.brdFanID[9, :] = np.array([5, INVALID_VALUE])

        self.fanCount = 5
        self.productType = 2  # 1=>16, 2=>08

        self.memory = Memory()

    def get_static_info(self):
        return self.boardType, self.fanCount, self.brdFanID, self.productType

    def step(self, Nx: np.ndarray, P: np.ndarray, time: float, T_env: float):
        Fan_u = self.Nx2U(Nx, Umax=300)
        slot_u = self.FanU_slotU_params @ Fan_u
        self.BrdPwr = P
        self.FanNx = Nx
        self.FanPwr = self.Nx2FanPwr(Nx)

        steps = time / 0.04
        temp = self.get_cpu_temp(
            steps, self.SensorTemp[0, 0], P[0], T_env, slot_u[0], *self.SensorParams[0, 0])
        self.SensorTemp[0, 0] = temp[-1]

        beginTime = self.memory.CPU_Temp_time[-1]
        self.memory.CPU_Temp += list(temp)
        self.memory.CPU_Temp_time += list(
            np.linspace(beginTime, beginTime + time, len(temp)))
        self.memory.Nx_time += [beginTime, beginTime + time]
        self.memory.Nx += [list(Nx), list(Nx)]
        self.memory.FanPwr += [self.FanPwr, self.FanPwr]
        self.memory.CPU_Temp_Point += [temp[-1], temp[-1]]
        self.memory.CPU_Pwr += [P[0], P[0]]
        self.memory.checkSize()

    def get_cpu_temp(self, n, T0, P, T_env, u, k2=0.187572, k3=0.05, Gamma=0.618):
        p = 1 - k2 * k3 * u**Gamma
        q = k3 * P + (1 - p) * T_env
        tmp = q / (p - 1)
        allTn = (T0 + tmp) * p**np.linspace(0, n, 10) - tmp
        # Tn = (T0 + tmp) * p**n - tmp
        return allTn

    def Nx2U(self, Nx, Umax=100):
        return Umax * (Nx/100)**0.7

    def Nx2FanPwr(self, Nx):
        return 528.107 * (np.mean(Nx) / 100)**2


T_env = 32
env = FanENV()

boardType, fanCount, brdFanID, productType = env.get_static_info()

fix, ax = plt.subplots(3, figsize=(20, 8), sharex=True)


while True:
    Nx = np.random.randint(20, 100, 5)
    BrdPwr = np.random.randint(20, 150, 24)
    time_step = 4  # s
    env.step(Nx, BrdPwr, time_step, T_env)

    for i in range(3):
        ax[i].cla()
    ax[0].plot(env.memory.Nx_time, np.array(env.memory.Nx)[:, 0], "o--")
    ax[0].set_ylabel("Nx")

    ax[1].plot(env.memory.CPU_Temp_time, env.memory.CPU_Temp, ":")
    ax[1].plot(env.memory.Nx_time[1::2], env.memory.CPU_Temp_Point[1::2], "o")
    ax[1].set_ylabel("CPU_Temp")

    ax[2].plot(env.memory.Nx_time, env.memory.CPU_Pwr, "-o")
    ax[2].set_ylabel("CPU_Pwr")

    plt.pause(1)
