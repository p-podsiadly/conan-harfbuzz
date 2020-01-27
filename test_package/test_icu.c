#ifdef TEST_ICU

#include <hb-icu.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    const char* script_code = "Grek";

    hb_script_t script = hb_script_from_string(script_code, -1);

    UScriptCode icu_script = hb_icu_script_from_script(script);

    const char* icu_name = uscript_getName(icu_script);

    printf("========\n");
    printf("ICU test\n");
    printf("Script code: %s\n", script_code);
    printf("ICU script name: %s\n", icu_name);

    return 0;
}

#else
int main(int argc, char **argv) { return 0; }
#endif