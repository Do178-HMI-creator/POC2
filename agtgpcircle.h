#ifndef AGTGPCIRCLE_H
#define AGTGPCIRCLE_H
#include "agtTypColor.h"
#include "agtTypPoint.h"
#include "agtgraphicprimitiveifc.h"

class agtGpCircle : public agtGraphicPrimitiveIfc
{
  public:
    agtGpCircle(std::string name_c, agtTypPoint get_centerPoint, agtTypColor get_rgb, float r = 0.5);
    void update(agtTypPoint get_centerPoint, agtTypColor get_rgb, float r);
    void update(std::string message) override;
    void draw() override;
    std::string getName() override;

  private:
    agtTypPoint centerPoint;
    agtTypColor rgb;
    float r;
};

#endif // AGTGPCIRCLE_H
