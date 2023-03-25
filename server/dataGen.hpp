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

}  // namespace Arash

#endif  // DATAGET_HPP