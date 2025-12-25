#include <OpenColorIO/OpenColorIO.h>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <unistd.h>

namespace OCIO = OCIO_NAMESPACE;

__AFL_FUZZ_INIT();

int main(int argc, char** argv) {

    unsigned char *buf = __AFL_FUZZ_TESTCASE_BUF;

    while (__AFL_LOOP(10000)) {
        int len = __AFL_FUZZ_TESTCASE_LEN;

        if (len > 0) {
            std::string input_str(reinterpret_cast<char*>(buf), len);
            std::istringstream is(input_str);

            try {
                OCIO::ConstConfigRcPtr config = OCIO::Config::CreateFromStream(is);

                if (config) {
                    try {
                        config->validate();
                    } catch (...) {}

                }

            } catch (const OCIO::Exception& e) {

            } catch (...) {

            }
        }
    }

    return 0;
}
