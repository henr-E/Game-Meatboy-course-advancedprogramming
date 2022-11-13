Project Advanced Programming 2022-2023
=======================================

Name: Henri Kerch  
Student number: s0211160

##circleCI
https://app.circleci.com/pipelines/github/AP-Lab-Sessions  
only admin access
##run from terminal
cd < directory >  
mkdir build  
cd build  
cmake ..  
make  
make install  
./installed/bin/hw  

##doxygen
the OUTPUT_DIRECTORY in the "doxygen config_file" is set to the "doxygen" directory
* ###changes in default config_file
  * EXTRACT_ALL            = YES
  * EXTRACT_PRIVATE        = YES
  * EXTRACT_PRIV_VIRTUAL   = YES
  * RECURSIVE              = NO
  * OUTPUT_DIRECTORY       = doxygen

* ###install
  * Doxygen installation command on mac: "brew install doxygen"
* ###create config_file for doxygen
  * doxygen -g config_file
* ###run doxygen
  * doxygen doxygen/config_file
* ###doxygen documentation
  ````
  /**
  * ... text ...
  */
  
  ///
  /// ... text ...
  ///
  ````

