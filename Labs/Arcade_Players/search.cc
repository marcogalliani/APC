#include <iostream>
#include <algorithm>

#include "search.hh"
#include "timing.hh"

namespace Arcade {

bool binary_search(const std::vector<Arcade::Player> &player_vec, unsigned player_username) {
  timing::time_point start = std::chrono::steady_clock::now();

  std::vector<Arcade::Player>::const_iterator begin = player_vec.begin(), end = player_vec.end(),
  // original musernamepoint
  musername = begin + (end - begin) / 2;
  unsigned n_iter = 1;

  while (begin != end and musername->getUsername() != player_username) {
    /* end is meant to be invalusername, so in both cases
     * we are ignoring musername at the following iteration
     */
    if (player_username < musername->getUsername())
      end = musername;
    else
      begin = musername + 1;

    musername = begin + (end - begin) / 2;
    ++n_iter;
  }

  std::cout << "Number of Iterations " << n_iter << "\n";

  timing::time_point finish = std::chrono::steady_clock::now();
  timing::elapsed_between(start, finish);

  if (musername != player_vec.end() and player_username == musername->getUsername()) {
    return true;
  } else {
    return false;
  }
}

/* Template for extracting time from the search methods to be implemented:
 *
 * timing::time_point start = std::chrono::steady_clock::now();
 * --- Search ---
 * timing::time_point finish = std::chrono::steady_clock::now();
 * timing::elapsed_between (start, finish);
 *
 * This will print the elapsed time for each search implementation */

bool stl_binary_search(const std::vector<Arcade::Player> &player_vec, unsigned int player_username){

    /*
    bool binary_search( player_vec_type::const_iterator first,
                        player_vec_type::const_iterator last, const Arcade::Player & value);
    */
    timing::time_point start = std::chrono::steady_clock::now();

    bool answer = std::binary_search(player_vec.cbegin(),player_vec.cend(),Player(player_username));

    timing::time_point finish = std::chrono::steady_clock::now();
    timing::elapsed_between (start, finish);

    return answer;

 }

bool set_search(const std::set<Arcade::Player> &player_set, unsigned int player_username) {

    timing::time_point start = std::chrono::steady_clock::now();

    //my code:
    //bool answer = player_set.find(Player(player_username))!= player_set.end();

    bool answer = player_set.count(Player(player_username));

    timing::time_point finish = std::chrono::steady_clock::now();
    timing::elapsed_between (start, finish);

    return answer;

}

bool map_search(const std::unordered_map<unsigned int, Arcade::Player> &player_map, unsigned int player_username) {

    timing::time_point start = std::chrono::steady_clock::now();

    //my code:
    //bool answer = player_map.find(player_username) != player_map.end();

    bool answer = player_map.count(player_username);

    timing::time_point finish = std::chrono::steady_clock::now();
    timing::elapsed_between (start, finish);

    return answer;

}


}


