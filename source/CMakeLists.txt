cmake_minimum_required (VERSION 3.8)
project( the_cpp )
#find_package(GSL REQUIRED)
#find_package(Eigen3 CONFIG REQUIRED)
add_executable( the_c main.cxx string_using.cxx 
    vector_using.cxx max_sub.cxx operator.cxx  statement.cxx 
    function.cxx sales.cxx m_sales.cxx screen.cxx consRef.cxx aggeregate.cxx iochap.cxx
    fileinout.cxx container.cpp stroper.cpp generic.cxx query.cpp ctor.cpp overload.cpp
    objector.cc templ.cc libfac.cc)
#target_link_libraries(the_c PRIVATE GSL::gsl GSL::gslcblas)
#target_link_libraries(the_c PRIVATE Eigen3::Eigen)