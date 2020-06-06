#include <iostream> 
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
int 
main (int argc, char** argv) 
{ 
	pcl::PointCloud<pcl::PointXYZ> cloud;
	cloud.width = 8; 
	cloud.height = 1; 
	cloud.is_dense = false; 
	cloud.points.resize (cloud.width * cloud.height); 
	std::cout<<"cloud-points-size:"<<cloud.points.size()<<std::endl;
	for (size_t i = 0; i < cloud.points.size (); ++i) 
	{ 
		cloud.points[i].x = -i; 
		cloud.points[i].y = -i; 
		cloud.points[i].z = -i; 
	} 
	pcl::io::savePCDFile ("savePCDFile.pcd", cloud);
	pcl::io::savePCDFileASCII ("savePCDFileASCII.pcd", cloud); 
	pcl::io::savePCDFileBinary ("savePCDFileASCII.pcd", cloud); 
	pcl::io::savePCDFileBinaryCompressed ("savePCDFileBinaryCompressed.pcd", cloud); 
	
	
	pcl::PCDWriter writer;
	writer.write ("PCDWriter.pcd", cloud);
	writer.writeASCII ("PCDWriterASCII.pcd", cloud);
	writer.writeBinary("PCDWriterBinbary.pcd", cloud);
	writer.writeBinaryCompressed("PCDWriterCompressed.pcd", cloud);

	std::cerr << "Saved " << cloud.points.size () << " data points to test_pcd.pcd." << std::endl; 
	for (size_t i = 0; i < cloud.points.size (); ++i) 
		std::cerr << "    " << cloud.points[i].x << " " << cloud.points[i].y << " " << cloud.points[i].z << std::endl; return (0);
	return 0;
}
