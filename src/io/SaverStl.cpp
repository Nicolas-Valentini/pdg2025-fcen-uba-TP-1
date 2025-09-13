//------------------------------------------------------------------------
//  Copyright (C) Gabriel Taubin
//  Time-stamp: <2025-08-04 22:14:44 gtaubin>
//------------------------------------------------------------------------
//
// SaverStl.cpp
//
// Written by: <Your Name>
//
// Software developed for the course
// Digital Geometry Processing
// Copyright (c) 2025, Gabriel Taubin
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of the Brown University nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL GABRIEL TAUBIN BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "SaverStl.hpp"
#include "wrl/IndexedFaceSet.hpp"
#include "wrl/Shape.hpp"
#include "wrl/Appearance.hpp"
#include "wrl/Material.hpp"
#include <filesystem>



const char* SaverStl::_ext = "stl";

void SaverStl::saveFace_(FILE* fp,vector<float>& normals, vector<float>& vertexs, Faces faces,const int iF) const {
    fprintf(fp, "facet normal ");
    for (int i = 0; i < 3; ++i) {
        fprintf(fp,"%f ",vertexs[iF*3+i]);
    }
    fprintf(fp,"\n  outer loop\n");
    for (int i = 0; i < faces.getFaceSize(iF); ++i) {
        fprintf(fp,"    vertex ");
        int corner = faces.getFaceVertex(iF,i);
        for (int j = 0; j < 3; ++j) {
            fprintf(fp,"%f ",vertexs[corner*3+j]);
        }
        fprintf(fp,"\n");
    }
    fprintf(fp,"  endloop\n");
    fprintf(fp,"endfacet\n");
}


//////////////////////////////////////////////////////////////////////
bool SaverStl::save(const char* filename, SceneGraph& wrl) const {
  bool success = false;
  if(filename!=(char*)0) {

    // Check these conditions

    // 1) the SceneGraph should have a single child
    // 2) the child should be a Shape node
    // 3) the geometry of the Shape node should be an IndexedFaceSet node

    // - construct an instance of the Faces class from the IndexedFaceSet
    // - remember to delete it when you are done with it (if necessary)
    //   before returning

    // 4) the IndexedFaceSet should be a triangle mesh
    // 5) the IndexedFaceSet should have normals per face

    // if (all the conditions are satisfied) {

    int nChildren = wrl.getNumberOfChildren();
    if(nChildren == 1){
        Node* node = wrl[0];
        if(node->isShape()){
            Shape* shape = (Shape*)node;
            Node* geometry = shape->getGeometry();
            if(geometry->isIndexedFaceSet()){
                IndexedFaceSet* indexedFaceSet = (IndexedFaceSet*)geometry;
                if(indexedFaceSet->isTriangleMesh()){
                    FILE* fp = fopen(filename,"w");
                    if(	fp!=(FILE*)0) {
                        // if set, use ifs->getName()
                        // otherwise use filename,
                        // but first remove directory and extension
                        string name = indexedFaceSet->getName();
                        if(name.empty()){
                            filesystem::path filePath = filesystem::path(filename);
                            name = filePath.stem().string();
                        }
                        fprintf(fp,"solid %s\n",name.c_str());
                        Faces faces = Faces(indexedFaceSet->getNumberOfCorners(),indexedFaceSet->getCoordIndex());
                        vector<float> normals = indexedFaceSet->getNormal();
                        vector<float> vertexs = indexedFaceSet->getCoord();
                        for (int iF = 0; iF < faces.getNumberOfFaces(); ++iF) {
                            saveFace_(fp,normals,vertexs, faces, iF);

                        }
                        fclose(fp);
                        success = true;
                    }

                }
            }
        }
    }
    // } endif (all the conditions are satisfied)
  }
  return success;
}
