/*
github: @mrzdev

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

// The Uuid class generates unique uuid using boost library

#include "uuid.hpp"

Uuid::Uuid(){};

boost::uuids::uuid Uuid::generate(){
    auto uuid = boost::uuids::random_generator()();
    return uuid;
}

std::string Uuid::toString(boost::uuids::uuid generated){
    std::string uuid = to_string(generated);
    return uuid;
}

int main(){
    std::shared_ptr<Uuid> uuid = std::make_shared<Uuid>();
    auto generated_uuid = uuid->generate();
    auto uuid_str = uuid->toString(generated_uuid);
    printf("%s\n", uuid_str.c_str());
    return 0;
}