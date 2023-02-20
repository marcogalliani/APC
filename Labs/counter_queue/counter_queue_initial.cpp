#include "counter_queue_initial.h"

namespace supermarket {
bool counter_queue::pick_number(const std::string &customer_id) {
  /* Your code goes here */

  const std::pair<std::unordered_set<std::string>::iterator ,bool> outcome = m_in_line.insert(customer_id);
  //complexity: avg -> O(1), wrst -> O(n)
  bool added_in_queue = outcome.second;

  if(added_in_queue)
      m_order.push(customer_id); //complexity: avg -> O(1), wrst -> O(n)

    return added_in_queue;
}

std::string counter_queue::next_customer() {
  /* Your code goes here */
  const std::string next = m_order.front();

  //removing the customer from the queue
  m_order.pop(); //complexity: avg -> O(1), wrst -> O(n)
  m_in_line.erase(next); //complexity: avg -> O(1), wrst -> O(n)

  return next;
}

bool counter_queue::empty() const {
  /* Your code goes here */
    return m_order.empty();
}
}
