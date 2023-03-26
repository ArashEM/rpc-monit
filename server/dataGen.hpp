#ifndef DATAGEN_HPP
#define DATAGEN_HPP

#include <chrono>
#include <iostream>
#include <thread>

namespace Arash {
/**
 * @brief callable object to show fake progress
*/
class dataGen {
   public:
    constexpr dataGen(int32_t cnt) : m_cnt{cnt} {};
    constexpr dataGen() : dataGen{0} {};
    int32_t cnt(void) const { return m_cnt; };
    void operator()() { m_cnt++; };

    /**
     * @brief Monitoring class
    */
    friend class dataGenMonit;

   private:
    int32_t m_cnt;
};

class Phy {
   public:
    explicit Phy(size_t rxCnt = 0, size_t txCnt = 0)
        : m_rxCounter{rxCnt}, m_txCounter{txCnt} {}
    size_t rxCounter(void) const { return m_rxCounter; }
    size_t txCounter(void) const { return m_txCounter; }
    void operator()(void) {
        m_rxCounter++;
        m_txCounter++;
    }

   private:
    size_t m_rxCounter;
    size_t m_txCounter;
};

class Mac {
   public:
    explicit Mac(size_t rxCnt = 0, size_t txCnt = 0)
        : m_rxCounter{rxCnt}, m_txCounter{txCnt} {}
    size_t rxCounter(void) const { return m_rxCounter; }
    size_t txCounter(void) const { return m_txCounter; }
    void operator()(void) {
        m_rxCounter++;
        m_txCounter++;
    }

   private:
    size_t m_rxCounter;
    size_t m_txCounter;
};

}  // namespace Arash

#endif  // DATAGET_HPP