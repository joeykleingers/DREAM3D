/* ============================================================================
 * Copyright (c) 2010, Michael A. Jackson (BlueQuartz Software)
 * Copyright (c) 2010, Dr. Michael A. Groeber (US Air Force Research Laboratories
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * Neither the name of Michael A. Groeber, Michael A. Jackson, the US Air Force,
 * BlueQuartz Software nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior written
 * permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  This code was written under United States Air Force Contract number
 *                           FA8650-07-D-5800
 *
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#ifndef HEXAGONALOPS_H_
#define HEXAGONALOPS_H_

#include "MXA/Common/MXASetGetMacros.h"
#include "DREAM3DLib/Common/OrientationMath.h"

namespace HexagonalMath {
  namespace Detail {

    static const float HexDim1InitValue = powf((0.75f*((float(M_PI)/2.0f)-sinf((float(M_PI)/2.0f)))),(1.0f/3.0f));
    static const float HexDim2InitValue = powf((0.75f*((float(M_PI)/2.0f)-sinf((float(M_PI)/2.0f)))),(1.0f/3.0f));
    static const float HexDim3InitValue = powf((0.75f*((float(M_PI)/6.0f)-sinf((float(M_PI)/6.0f)))),(1.0f/3.0f));
    static const float HexDim1StepValue = HexDim1InitValue/18.0f;
    static const float HexDim2StepValue = HexDim2InitValue/18.0f;
    static const float HexDim3StepValue = HexDim3InitValue/6.0f;
    static const float HexQuatSym[12][5] = {{0.000000000f, 0.000000000f, 0.000000000f, 0.000000000f, 1.000000000f},
                         {0.000000000f, 0.000000000f, 0.000000000f, 0.500000000f, 0.866025400f},
                         {0.000000000f, 0.000000000f, 0.000000000f, 0.866025400f, 0.500000000f},
                         {0.000000000f, 0.000000000f, 0.000000000f, 1.000000000f, 0.000000000f},
                         {0.000000000f, 0.000000000f, 0.000000000f, 0.866025400f, -0.50000000f},
                         {0.000000000f, 0.000000000f, 0.000000000f, 0.500000000f, -0.86602540f},
                         {0.000000000f, 1.000000000f, 0.000000000f, 0.000000000f, 0.000000000f},
                         {0.000000000f, 0.866025400f, 0.500000000f, 0.000000000f, 0.000000000f},
                         {0.000000000f, 0.500000000f, 0.866025400f, 0.000000000f, 0.000000000f},
                         {0.000000000f, 0.000000000f, 1.000000000f, 0.000000000f, 0.000000000f},
                         {0.000000000f, -0.50000000f, 0.866025400f, 0.000000000f, 0.000000000f},
                         {0.000000000f, -0.86602540f, 0.500000000f, 0.000000000f, 0.000000000}};
    static const float HexRodSym[12][3] = {{0.0f, 0.0f, 0.0f},
                      {0.0f, 0.0f, 0.57735f},
                      {0.0f, 0.0f, 1.73205f},
                      {0.0f, 0.0f, 1000000000000.0f},
                      {0.0f, 0.0f, -1.73205f},
                      {0.0f, 0.0f, -0.57735f},
                      {1000000000000.0f, 0.0f, 0.0f},
                      {8660254000000.0f, 5000000000000.0f, 0.0f},
                      {5000000000000.0f, 8660254000000.0f, 0.0f},
                      {0.0f, 1000000000000.0f, 0.0f},
					  {-5000000000000.0f, 8660254000000.0f, 0.0f},
                      {-8660254000000.0f, 5000000000000.0f, 0.0f}};
  }
}

/**
 * @class HexagonalOps HexagonalOps.h AIM/Common/OrientationOps/HexagonalOps.h
 * @brief
 * @author Michael A. Jackson for BlueQuartz Software
 * @author Michael A. Groeber for USAF Research Laboratory, Materials Lab
 * @date May 5, 2011
 * @version 1.0
 */
class DREAM3DLib_EXPORT HexagonalOps : public OrientationMath
{
  public:
    MXA_SHARED_POINTERS(HexagonalOps)
    MXA_TYPE_MACRO(HexagonalOps)
    MXA_STATIC_NEW_MACRO(HexagonalOps);

    HexagonalOps();
    virtual ~HexagonalOps();

    int getODFSize() { return 15552; }
    int getMDFSize() { return 15552; }

    virtual float getMisoQuat( float q1[5],float q2[5],float &n1,float &n2,float &n3);
    virtual void getODFFZRod(float &r1,float &r2, float &r3);
    virtual void getMDFFZRod(float &r1,float &r2, float &r3);
    virtual void getNearestQuat(float *q1, float *q2);
    virtual void getFZQuat(float *qr);
    virtual int getMisoBin(float r1, float r2, float r3);
    virtual void determineEulerAngles(int choose, float &synea1, float &synea2, float &synea3);
    virtual void determineRodriguesVector(int choose, float &r1, float &r2, float &r3);
    virtual int getOdfBin(float r1, float r2, float r3);
	virtual void getSchmidFactorAndSS(float loadx, float loady, float loadz, float &schmidfactor, int &slipsys);

  protected:
    float _calcMisoQuat(const float quatsym[24][5], int numsym,
                  float q1[5], float q2[5],
                  float &n1, float &n2, float &n3);

  private:
    HexagonalOps(const HexagonalOps&); // Copy Constructor Not Implemented
    void operator=(const HexagonalOps&); // Operator '=' Not Implemented
};

#endif /* HEXAGONALOPS_H_ */
