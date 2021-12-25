#ifndef SPRITE_ANIMATOR_H
#define SPRITE_ANIMATOR_H
#include <vector>
class sprite_animator
{
public:
    sprite_animator(float sheet_height, float sheet_width);

    typedef struct sheet_square
    {
        unsigned int top_left_pixel;
        unsigned int top_right_pixel;
        unsigned int bottom_left_pixel;
        unsigned int bottom_right_pixel;
        sheet_square& operator+ (const sheet_square& right);
        sheet_square& operator- (const sheet_square& right);
    } sheet_square;

    typedef struct normalized_sheet_square
    {
        float top_left_normal;
        float top_right_normal;
        float bottom_left_normal;
        float bottom_right_normal;
        normalized_sheet_square(sheet_square& normalize_me);
    }normalized_sheet_square;

    void animate(
        std::vector<unsigned int> horizontal_shift_offsets,
        std::vector<sheet_square> frame_dimensions);

    

};


#endif /* SPRITE_ANIMATOR_H */