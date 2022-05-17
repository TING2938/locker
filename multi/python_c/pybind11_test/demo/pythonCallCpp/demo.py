try:
    import sys
    sys.path.append("build/demo/pythonCallCpp")
except:
    pass

import pythonCallCpp as p

print(p.func([2, 4, 7]))

xm = p.Student("xiaoming")

xm.setAge(18)
xm.setScore([90, 85, 86])

xm.print()

print("mean score: ", p.calc_mean_score(xm))
