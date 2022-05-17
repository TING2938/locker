#include <pybind11/embed.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <iostream>

namespace py = pybind11;
using namespace std;
using namespace pybind11::literals;

void basic()
{
    cout << "Hello PyBind World" << endl;

    py::module math   = py::module::import("math");
    py::object result = math.attr("sqrt")(25);
    std::cout << "Sqrt of 25 is: " << result.cast<float>() << std::endl;
}

void matplotlib_1()
{
    auto plt           = py::module::import("matplotlib.pyplot");
    std::vector<int> x = {1, 2, 3};
    std::vector<int> y = {3, 2, 5};
    plt.attr("plot")(x, y, "--o", "color"_a = "r");
    plt.attr("show")();
}

void matplotlib_2()
{
    auto plt           = py::module::import("matplotlib.pyplot");
    std::vector<int> x = {1, 2, 3};
    std::vector<int> y = {3, 2, 5};

    py::tuple res = plt.attr("subplots")(2, 1, "figsize"_a = py::make_tuple(10, 8));
    auto fig      = res[0];
    py::tuple ax  = res[1];
    py::print(py::str(ax));

    ax[0].attr("plot")(x, y);
    ax[1].attr("plot")(x, y);
    plt.attr("show")();
}

void list_vector()
{
    auto pytuple      = py::make_tuple(3, 2, 5);
    py::object pylist = pytuple;
    auto aaam         = py::cast<std::vector<int>>(pylist);
    for (auto&& a : aaam) {
        std::cout << a << std::endl;
    }
}

int main()
{
    py::scoped_interpreter guard{};
    list_vector();
}