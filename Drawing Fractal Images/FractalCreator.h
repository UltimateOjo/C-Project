#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include"Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include"RGB.h"
#include <string>
#include<cstdint>
#include<memory>
#include<vector>
#include<math.h>
using namespace std;

class FractalCreator {
private:
  int m_width;
  int m_height;
  unique_ptr<int[]> m_histogram;
	unique_ptr<int[]> m_fractal;
  Bitmap m_bitmap;
  ZoomList m_zoomList;
  int m_total{0};

  vector <double> m_ranges;
  vector <RGB> m_colors;
  vector<int> m_rangeTotals;

  bool m_bGotFirstRange{false};
private:

  void calculateIteration();
  void calculateTotalIterations();
  void calculateRangeTotals();
  void drawFractal();

  void writeBitmap(string name);
public:
  int getRange(int iterations) const;
  void run(string name);
  void addRange(double rangeEnd, const RGB& rgb);
  void addZoom(const Zoom& zoom);
  FractalCreator(int width, int height);
  virtual ~FractalCreator();
};


#endif
