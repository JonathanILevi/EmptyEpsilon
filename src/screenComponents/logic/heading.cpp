#include "gameGlobalInfo.h"
#include "heading.h"

string showAngle(float angle, bool short_) {
    return showHeading(angle+90, short_);
}
string showHeading(float heading, bool short_) {
    if (gameGlobalInfo->bearing_type == BT_Normal) {
        if (short_) return string(int(round(fmodf(heading + 360.f, 360.f))));
        return string(fmodf(heading + 360.f, 360.f), 1);
    }
    if (gameGlobalInfo->bearing_type == BT_Twelve) {
        string end;
        if (short_) end = string(int(round(fmodf((heading+360.f)/2.5f, 12.f))));
        else end = string(fmodf((heading+360.f)/2.5f, 12.f), 1);
        return string((int)fmodf((heading+360.f)/30, 12.f))
                +':'
                +end;
    }
}