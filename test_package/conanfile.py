from conans import ConanFile, CMake, tools
import os

class TestPackageConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def _run_test(self, name):
        self.run(os.path.join("bin", name), run_environment=True)

    def test(self):
        if not tools.cross_building(self.settings):
            self._run_test("test_package")
            self._run_test("test_package_icu")
