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
        m_server.bind("cnx", [&]() { return m_gen.m_cnt; });
        m_server.async_run();
    };
    ~dataGenMonit() { rpc::this_server().stop(); }

   private:
    const dataGen& m_gen;
    const std::string m_name;
    rpc::server m_server;
};

class dataMonit {
   public:
    dataMonit(size_t phyRxCnt = 0, size_t phyTxCnt = 0, size_t macRxCnt = 0,
              size_t macTxCnt = 0)
        : m_phyRxCounter{phyRxCnt},
          m_phyTxCounter{phyTxCnt},
          m_macRxCounter{macRxCnt},
          m_macTxCounter{macTxCnt} {}

   public:
    size_t m_phyRxCounter;
    size_t m_phyTxCounter;
    size_t m_macRxCounter;
    size_t m_macTxCounter;
    MSGPACK_DEFINE_ARRAY(m_phyRxCounter, m_phyTxCounter, m_macRxCounter,
                         m_macTxCounter);
};

}  // namespace Arash

#endif  // DATAGENMONIT_HPP