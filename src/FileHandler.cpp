#include <string>
#include <unistd.h>
#include <linux/limits.h>
#include <sstream>
#include <fstream>
#include <iostream>
namespace FileHandler {

	std::string resolvePath(const char* path){
		std::string strPath(path);
		if(strPath.substr(0,2) == "./" ){ //relative path
			char cwd[PATH_MAX];
			getcwd(cwd, sizeof(cwd));

			std::string basePath(cwd);
			basePath.replace(basePath.end(), basePath.end()-5,"src");

			strPath.replace(strPath.begin(), strPath.begin(),basePath);

			return strPath;
			std::cout << "resolved Path: " << strPath << std::endl;
		}
		return strPath;
	}

	std::string readFromFile(const char* path){
		std::string resolvedPath = resolvePath(path);
		std::ifstream fileStream(resolvedPath);
		std::stringstream ss;
		ss << fileStream.rdbuf();
		std::string fileContent = ss.str();
		return fileContent;
	}
}
