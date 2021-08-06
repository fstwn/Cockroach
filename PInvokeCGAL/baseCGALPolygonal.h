#pragma once

#define PINVOKE extern "C" __declspec(dllexport)
#define deletePtr(ptr, isArray) if (isArray) {delete[] arr;} else {delete arr;}

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Point_set_3/IO.h>
#include <CGAL/Point_set_3.h>
#include <CGAL/property_map.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/compute_average_spacing.h>
#include <CGAL/Shape_detection/Efficient_RANSAC.h>
#include <CGAL/Polygonal_surface_reconstruction.h>
#include <vector>
#include <string>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::Point_3 Point;
typedef Kernel::Vector_3 Vector;
// Point with normal, and plane index
typedef boost::tuple<Point, Vector, int> PNI;
typedef std::vector<PNI> Point_vector;
typedef CGAL::Nth_of_tuple_property_map<0, PNI> Point_map;
typedef CGAL::Nth_of_tuple_property_map<1, PNI> Normal_map;
typedef CGAL::Nth_of_tuple_property_map<2, PNI> Plane_index_map;
typedef CGAL::Shape_detection::Efficient_RANSAC_traits<Kernel, Point_vector, Point_map, Normal_map> Traits;
typedef CGAL::Shape_detection::Efficient_RANSAC<Traits> Efficient_ransac;
typedef CGAL::Shape_detection::Plane<Traits> Plane;
typedef CGAL::Shape_detection::Point_to_shape_index_map<Traits> Point_to_shape_index_map;
typedef CGAL::Polygonal_surface_reconstruction<Kernel> Polygonal_surface_reconstruction;
typedef CGAL::Surface_mesh<Point> Surface_mesh;


PINVOKE void ComputePolygonalSurfaceReconstruction (

	double* p, size_t p_c,
	double* n, size_t n_c,
	double* c, size_t c_c,

	double radius,// = 0.1,
	int iterations,// = 30,
	int neighbours,// = 100, //reorientation

	double*& p_o, int& p_c_o,
	double*& n_o, int& n_c_o,
	double*& c_o, int& c_c_o
);