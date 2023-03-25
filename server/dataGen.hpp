#ifndef DATAGEN_HPP
#define DATAGEN_HPP

#include <chrono>
#include <iostream>
#include <thread>

namespace Arash {
class dataGen {
   public:
    dataGen(int32_t cnt) : m_cnt{cnt} {};
    dataGen() : dataGen{0} {};
    int32_t cnt(void) const { return m_cnt; };
    void operator()() { m_cnt++; };

    friend class dataGenMonit;

   private:
    int32_t m_cnt;
};

}  // namespace Arash

#endif  // DATAGET_HPP