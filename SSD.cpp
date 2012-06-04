#include "SSD.h"

#include "itkImageRegionConstIterator.h"

#include "PixelDifferences.h"

float SSDGeneral::operator()(const ImageType* const image, const itk::ImageRegion<2>& region1, const itk::ImageRegion<2>& region2)
{
  assert(region1.GetSize() == region2.GetSize());
  assert(image->GetLargestPossibleRegion().IsInside(region1));
  assert(image->GetLargestPossibleRegion().IsInside(region2));

  itk::ImageRegionConstIterator<ImageType> patch1Iterator(image, region1);
  itk::ImageRegionConstIterator<ImageType> patch2Iterator(image, region2);

  float sumSquaredDifferences = 0;

  ImageType::PixelType pixel1;
  ImageType::PixelType pixel2;

  while(!patch1Iterator.IsAtEnd())
    {
    pixel1 = patch1Iterator.Get();
    pixel2 = patch2Iterator.Get();

    SumOfSquaredDifferencesGeneral sumOfSquaredDifferencesFunctor;
    float squaredDifference = sumOfSquaredDifferencesFunctor(pixel1, pixel2);

//       std::cout << "Source pixel: " << static_cast<unsigned int>(sourcePixel)
//                 << " target pixel: " << static_cast<unsigned int>(targetPixel)
//                 << "Difference: " << difference << " squaredDifference: " << squaredDifference << std::endl;

    sumSquaredDifferences +=  squaredDifference;

    ++patch1Iterator;
    ++patch2Iterator;
    } // end while iterate over sourcePatch


  unsigned int numberOfPixels = region1.GetNumberOfPixels();

  float averageSSD = sumSquaredDifferences / static_cast<float>(numberOfPixels);

  return averageSSD;
}