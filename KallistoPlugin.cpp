#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "KallistoPlugin.h"

void KallistoPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 while (!ifile.eof()) {
   std::string filename;
   ifile >> filename;
   fastqFiles.push_back(filename);
 }
}

void KallistoPlugin::run() {
   
}

void KallistoPlugin::output(std::string file) {
  // Index is first fastq
  // kallisto quant -i /biorg/data/IDX/human_index.idx -o . --pseudobam --plaintext S12_R1.good.fq S12_R2.good.fq
   std::string command = "kallisto quant ";
   if (fastqFiles[0][0] != '/')
    command += " -i "+ std::string(PluginManager::prefix())+"/"+fastqFiles[0];
   else
    command += " -i "+ fastqFiles[0];
   command += " -o ";
   command += file;
   command += " --pseudobam --plaintext -t 48 ";
   if (fastqFiles[1][0] != '/')
    command += std::string(PluginManager::prefix())+"/"+fastqFiles[1];
   else
    command += fastqFiles[1];
   command += " ";
   if (fastqFiles[2][0] != '/')
    command += std::string(PluginManager::prefix())+"/"+fastqFiles[2];
   else
    command += fastqFiles[2];
 std::cout << command << std::endl;

 system(command.c_str());
}

PluginProxy<KallistoPlugin> KallistoPluginProxy = PluginProxy<KallistoPlugin>("Kallisto", PluginManager::getInstance());
