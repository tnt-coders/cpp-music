from conans import ConanFile, CMake, tools

class CppMusic(ConanFile):
    author = "TNT Coders <tnt-coders@googlegroups.com>"
    build_requires = "catch2/3.0.0@tnt-coders/testing"
    default_options = {"shared": False}
    description = "C++ library for storing and analyzing musical data"
    exports_sources = "CMakeLists.txt", "docs/*", "include/*", "src/*", "test/*"
    generators = "cmake"
    license = "GNU Lesser General Public License v3.0"
    name = "cpp-music"
    options = {"shared": [True, False]}
    settings = "os", "compiler", "build_type", "arch"
    topics = ("music")
    url = "https://github.com/tnt-coders/cpp-music"
    version = "0.0.0"

    def configure(self):
        tools.check_min_cppstd(self, "17")

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()
        cmake.test()

    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = self.collect_libs()

    def _configure_cmake(self):
        cmake = CMake(self)
        cmake.configure()
        return cmake