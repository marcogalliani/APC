#ifndef EXERCISE__COUNTER_QUEUE_H
#define EXERCISE__COUNTER_QUEUE_H

#include <string>
#include <queue>
#include <unordered_set>

namespace supermarket
{
class counter_queue
{
  /* Your data structure(s) goes here */

  std::queue<std::string> m_order;
  std::unordered_set<std::string> m_in_line;


public:
  bool pick_number(const std::string &customer_id);

  std::string next_customer(void);

  bool empty(void) const;
};
}

#endif //EXERCISE__COUNTER_QUEUE_H
