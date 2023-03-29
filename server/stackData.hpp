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

    stackData(size_t phyRxCnt = 0, size_t phyTxCnt = 0, size_t phyErrCnt = 0,
              size_t macRxCnt = 0, size_t macTxCnt = 0, size_t macErrCnt = 0,
              size_t txQuSizeCnt = 0, size_t txQuErrCnt = 0,
              size_t rxQueSizeCnt = 0, size_t rxQuErrCnt = 0,
              size_t stackRxCnt = 0, size_t stackTxCnt = 0,
              size_t stackDrpCnt = 0, size_t stackNumSockCnt = 0)
        : m_array{{phyRxCnt, phyTxCnt, phyErrCnt, macRxCnt, macTxCnt, macErrCnt,
                   txQuSizeCnt, txQuErrCnt, rxQueSizeCnt, rxQuErrCnt,
                   stackRxCnt, stackTxCnt, stackDrpCnt, stackNumSockCnt}} {}

    size_t& operator[](enum INDEX index) { return m_array.at(index); }

    /* MSGPACK required public member data */
    //private:
    std::array<size_t, INDEX::ENUM_MAX> m_array;
    MSGPACK_DEFINE_ARRAY(m_array);
};

}  // namespace Arash
