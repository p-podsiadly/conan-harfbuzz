#ifdef TEST_UNISCRIBE

#include <hb-uniscribe.h>
#include <hb-gdi.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    HFONT h_font
        = CreateFontA(
            18, 0, 0, 0, FW_NORMAL,
            FALSE, FALSE, FALSE, ANSI_CHARSET,
            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
            DEFAULT_QUALITY, FF_DONTCARE, NULL);
    
    hb_face_t* hb_face = hb_gdi_face_create(h_font);
    hb_font_t* hb_font = hb_font_create(hb_face);

    LOGFONTW* log_font = hb_uniscribe_font_get_logfontw(hb_font);
    
    hb_font_destroy(hb_font);
    hb_face_destroy(hb_face);
    DeleteObject(h_font);

    printf("==============\n");
    printf("Uniscribe test\n");

    return 0;
}

#else
int main(int argc, char** argv) { return 0; }
#endif
