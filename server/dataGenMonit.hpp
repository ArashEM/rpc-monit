#ifndef DATAGENMONIT_HPP
#define DATAGENMONIT_HPP

#include <iostream>
#include <string>

#include "dataGen.hpp"
#include "rpc/server.h"
#include "rpc/this_server.h"

namespace Arash {
/**
 * @brief Monitor dataGen object and report it's status via rpc
*/
class dataGenMonit {
   public:
    dataGenMonit(const dataGen& gen, std::string name)
        : m_gen{gen},
          m_name{name},
          m_server{"0.0.0.0", rpc::constants::DEFAULT_PORT} {
        m_server.bind("name", [&]() { return m_name; });
        m_server.bind("cnt", [&]() { return m_gen.m_cnt; });
        m_server.async_run();
    };
    ~dataGenMonit() { rpc::this_server().stop(); }

   private:
    const dataGen& m_gen;
    const std::string m_name;
    rpc::server m_server;
};
}  // namespace Arash

#endif  // DATAGENMONIT_HPP