#include <stdio.h>

#ifdef TEST_GDI_AND_UNISCRIBE

#include <hb-gdi.h>
#include <hb-uniscribe.h>

void test_gdi_and_uniscribe(void)
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

    printf("======================\n");
    printf("GDI and Uniscribe test\n");
}

#else
void test_gdi_and_uniscribe(void) {}
#endif

#ifdef TEST_GLIB

#include <hb-glib.h>

void test_glib(void)
{
    printf("=========\n");
    printf("GLib test\n");

    hb_glib_get_unicode_funcs();
}

#else
void test_glib(void) {}
#endif

#ifdef TEST_ICU

#include <hb-icu.h>

void test_icu(void)
{
    const char* script_code = "Grek";

    hb_script_t script = hb_script_from_string(script_code, -1);

    UScriptCode icu_script = hb_icu_script_from_script(script);

    const char* icu_name = uscript_getName(icu_script);

    printf("========\n");
    printf("ICU test\n");
    printf("Script code: %s\n", script_code);
    printf("ICU script name: %s\n", icu_name);
}

#else
void test_icu(void) {}
#endif

int main(int argc, char** argv)
{
    test_gdi_and_uniscribe();
    test_glib();
    test_icu();

    return 0;
}