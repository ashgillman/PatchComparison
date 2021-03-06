#ifndef PatchDistance_HPP
#define PatchDistance_HPP

#include "PatchDistance.h"

template <typename TImage>
void PatchDistance<TImage>::SetImage(TImage* const image)
{
  this->Image = image;
}

template <typename TImage>
void PatchDistance<TImage>::SetDistanceNameModifier(const std::string& distanceNameModifier)
{
  this->DistanceNameModifier = distanceNameModifier;
}

#endif
