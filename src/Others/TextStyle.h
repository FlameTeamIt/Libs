#ifndef TEXTSTYLE_H
#define TEXTSTYLE_H

/*

атрибуты
0	нормальный режим
1	жирный
4	подчеркнутый
5	мигающий
7	инвертированные цвета
8	невидимый
цвет текста
30	черный
31	красный
32	зеленый
33	желтый
34	синий
35	пурпурный
36	голубой
37	белый
цвет фона
40	черный
41	красный
42	зеленый
43	желтый
44	синий
45	пурпурный
46	голубой
47	белый
 */

#define TEXT_STYLE_NULL "\033[0m" // сброс

#define TEXT_STYLE_BOLD "\033[1m"
#define TEXT_STYLE_MIDDLE "\033[2m"
#define TEXT_STYLE_LIGHT "\033[3m"
#define TEXT_STYLE_UNDERLINE "\033[4m"
#define TEXT_STYLE_BINK "\033[5m"
#define TEXT_STYLE_INVERT "\033[7m"
#define TEXT_STYLE_INVISIBLE "\033[8m"

#define TEXT_STYLE_BLACK "\033[30m"
#define TEXT_STYLE_RED "\033[31m"
#define TEXT_STYLE_GREEN "\033[32m"
#define TEXT_STYLE_YELLOW "\033[33m"
#define TEXT_STYLE_BLUE "\033[34m"
#define TEXT_STYLE_VIOLET "\033[35m"
#define TEXT_STYLE_CYAN "\033[36m"
#define TEXT_STYLE_WHITE "\033[37m"

#define TEXT_STYLE_BLACK_BACKGROUND "\033[40m"
#define TEXT_STYLE_RED_BACKGROUND "\033[41m"
#define TEXT_STYLE_GREEN_BACKGROUND "\033[42m"
#define TEXT_STYLE_YELLOW_BACKGROUND "\033[43m"
#define TEXT_STYLE_BLUE_BACKGROUND "\033[44m"
#define TEXT_STYLE_VIOLET_BACKGROUND "\033[45m"
#define TEXT_STYLE_CYAN_BACKGROUND "\033[46m"
#define TEXT_STYLE_WHITE_BACKGROUND "\033[47m"

#endif // TEXTSTYLE_H
