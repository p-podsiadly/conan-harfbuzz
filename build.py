#!/usr/bin/env python
# -*- coding: utf-8 -*-

import platform
from bincrafters import build_template_default

if __name__ == "__main__":

    builder = build_template_default.get_builder()
    builder.run()

    builder = build_template_default.get_builder(options=["harfbuzz:with_glib=True", "harfbuzz:with_icu=True"])
    builder.run()
