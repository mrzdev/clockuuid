#ifndef UUID_H // include guard
#define UUID_H

#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <stdio.h>
#include <memory>

class Uuid{
    public:
        Uuid();
        boost::uuids::uuid generate();
        std::string toString(boost::uuids::uuid generated);
};

#endif