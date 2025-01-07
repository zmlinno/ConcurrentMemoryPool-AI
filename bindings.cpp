//
//  bindings.cpp
//  ProJect1
//
//  Created by 张木林 on 1/7/25.
//

#include<pybind11/pybind11.h>
#include<Python.h>
#include<pybind11/stl.h>

#include <vector>
using namespace std;
// 包含内核函数
#include "Test.cpp"

namespace py = pybind11;

PYBIND11_MODULE(spmv_kernel, m)
{
    m.def("spmv", &spmv, "A function to perform sparse matrix-vector multiplication");
}
