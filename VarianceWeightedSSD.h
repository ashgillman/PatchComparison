/*=========================================================================
 *
 *  Copyright David Doria 2011 daviddoria@gmail.com
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef VarianceWeightedSSD_H
#define VarianceWeightedSSD_H

#include "WeightedSSD.h"

// ITK
#include "itkVectorImage.h"

// STL
#include <vector>

/** This class weights pixels by their variance (computed normally - that is, without knowing anything
  * about a patch comparison application. */

class VarianceWeightedSSD : public WeightedSSD
{
public:

  /** Compute the variance on the fly. */
  template <typename TPixel>
  float operator()(const itk::VectorImage<TPixel, 2>* const image,
                   const itk::ImageRegion<2>& region1, const itk::ImageRegion<2>& region2);

  /** Use a precomputed variance image. */
  template <typename TPixel>
  float operator()(const itk::VectorImage<TPixel, 2>* const image,
                   const itk::Image<float, 2>* const varianceImage,
                   const itk::ImageRegion<2>& region1, const itk::ImageRegion<2>& region2);

};

#include "VarianceWeightedSSD.hpp"

#endif
