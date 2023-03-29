#include <array>
#include <iostream>
#include <stdexcept>

#include "rpc/server.h"

namespace Arash {
class stackData {
   public:
    enum INDEX {
        PHY_RX = 0,
        PHY_TX,
        PHY_ERR,
        MAC_RX,
        MAC_TX,
        MAC_ERR,
        TXQUEUE_SIZE,
        TXQUEUE_ERR,
        RXQUEUE_SIZE,
        RXQUEUE_ERR,
        STACK_RX,
        STACK_TX,
        STACK_DRP,
        STACK_SOCKETS,
        ENUM_MAX
    };

    stackData(size_t phyRxInit = 0, size_t phyTxInit = 0, size_t phyErrInit = 0,
              size_t macRxInit = 0, size_t macTxInit = 0, size_t macErrInit = 0,
              size_t txQuSizeInit = 0, size_t txQuErrInit = 0,
              size_t rxQueSizeInit = 0, size_t rxQuErrInit = 0,
              size_t stackRxInit = 0, size_t stackTxInit = 0,
              size_t stackDrpInit = 0, size_t stackNumSockInit = 0)
        : m_array{{phyRxInit, phyTxInit, phyErrInit, macRxInit, macTxInit,
                   macErrInit, txQuSizeInit, txQuErrInit, rxQueSizeInit,
                   rxQuErrInit, stackRxInit, stackTxInit, stackDrpInit,
                   stackNumSockInit}} {}

    size_t& operator[](enum INDEX index) { return m_array.at(index); }

   private:
    std::array<size_t, INDEX::ENUM_MAX> m_array;
    MSGPACK_DEFINE_ARRAY(m_array);
};


}  // namespace Arash
