#include "font_info.h"

font_char_locations populate_font_info()
{
    font_char_locations font_char_loc;
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('A', { {0,0}   , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('B', { {12,0}  , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('C', { {24,0}  , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('D', { {36,0}  , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('E', { {48,0}  , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('F', { {60,0}  , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('G', { {72,0}  , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('H', { {84,0}  , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('I', { {96,0}  , {8, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('J', { {106,0} , {11, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('K', { {119,0} , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('L', { {131,0} , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('M', { {143,0} , {11, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('N', { {0,38}  , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('O', { {12,38} , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('P', { {24,38} , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('Q', { {36,38} , {12, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('R', { {50,38} , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('S', { {62,38} , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('T', { {74,38} , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('U', { {86,38} , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('V', { {98,38} , {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('W', { {110,38}, {11, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('X', { {123,38}, {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('Y', { {135,38}, {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('Z', { {147,38}, {10, 14} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>(' ', { {0,0}   , {0, 0} }  ));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('a', { {0,19}   , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('b', { {12,19}  , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('c', { {24,19}  , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('d', { {36,19}  , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('e', { {48,19}  , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('f', { {60,19}  , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('g', { {72,19}  , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('h', { {84,19}  , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('i', { {97,19}  , {6, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('j', { {106,19} , {10, 15} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('k', { {119,19} , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('l', { {133,19} , {6, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('m', { {142,19} , {12, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('n', { {0,55}   , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('o', { {12,55}  , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('p', { {24,55}  , {10, 16} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('q', { {38,55}  , {10, 16} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('r', { {50,55}  , {9, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('s', { {62,55}  , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('t', { {74,55}  , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('u', { {86,55}  , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('v', { {98,55}  , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('w', { {110,55} , {12, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('x', { {123,55} , {10, 14} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('y', { {135,55} , {10, 15} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('z', { {147,55} , {10, 14} }));

    font_char_loc.insert(std::make_pair<char, pixel_font_info>('0', { {0,  91} , {11, 16} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('1', { {12, 91} , {10, 16} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('2', { {23, 91} , {12, 16} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('3', { {36, 91} , {12, 16} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('4', { {49, 91} , {12, 16} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('5', { {62, 91} , {12, 16} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('6', { {75, 91} , {12, 16} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('7', { {88, 91} , {12, 16} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('8', { {101,91} , {12, 16} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('9', { {114,91} , {12, 16} }));

    font_char_loc.insert(std::make_pair<char, pixel_font_info>('.', { {111,72} , {6,  17} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('?', { {131,72} , {13, 17} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>(',', { {123,72} , {7,  17} }));
    font_char_loc.insert(std::make_pair<char, pixel_font_info>('!', { {148,72} , {7,  17} }));

    return font_char_loc;
}
