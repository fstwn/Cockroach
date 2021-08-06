#include "baseCGALPolygonal.h"


PINVOKE void ComputePolygonalSurfaceReconstruction(

    double* p, size_t p_c,
    double* n, size_t n_c,
    double* c, size_t c_c,

    double radius,// = 0.1,
    int iterations,// = 30,
    int neighbours,// = 100, //reorientation

    double*& p_o, int& p_c_o,
    double*& n_o, int& n_c_o,
    double*& c_o, int& c_c_o
) {


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //Convert Input to CGAL PointCloud
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   // std::list<PointVectorPair> points;
    CGAL::Point_set_3<Kernel::Point_3, Kernel::Vector_3> points;
    points.resize(p_c);

}