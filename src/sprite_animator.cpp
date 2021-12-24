#include "sprite_animator.h"

sprite_animator::sheet_square& sprite_animator::sheet_square::operator+(
    const sheet_square& right)
{
    top_left_pixel      += right.top_left_pixel;
    top_right_pixel     += right.top_right_pixel;
    bottom_left_pixel   += right.bottom_left_pixel;
    bottom_right_pixel  += right.bottom_right_pixel;

    return *this;
}
sprite_animator::sheet_square& sprite_animator::sheet_square::operator-(
    const sheet_square& right)
{
    top_left_pixel      -= right.top_left_pixel;
    top_right_pixel     -= right.top_right_pixel;
    bottom_left_pixel   -= right.bottom_left_pixel;
    bottom_right_pixel  -= right.bottom_right_pixel;

    return *this;
}

sprite_animator::normalized_sheet_square::normalized_sheet_square(
    sheet_square& normalize_me)
{
    
}