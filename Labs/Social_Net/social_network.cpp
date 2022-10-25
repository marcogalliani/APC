///Header include
#include "social_network.hpp"
#include "user.hpp"

///STD include
#include <iostream>

namespace SocialNetworkNS {
size_t SocialNetwork::CUserIndex(const std::string &name,
                                 const std::string &surname) const {
  size_t i;

  User u(name, surname);

  bool found = false;

  for (i = 0; i < users.size() && !found; ++i)
    if (users[i] == u)
      found = true;

  if (found)
    return --i;
  else
    return users.size();
}

void SocialNetwork::AddUser(const std::string &name,
                            const std::string &surname) {

  /* YOUR CODE GOES HERE */
  size_t index = CUserIndex(name,surname);
  std::vector<size_t> init;

  if (index==users.size()){
      users.push_back(User(name,surname));
      friends.push_back(init);
  }

}

const std::vector<User> SocialNetwork::CGetUsers() const {
  return users;
}

const std::vector<User> SocialNetwork::CGetFriends(const User &user) const {

  /* YOUR CODE GOES HERE */
  return CGetFriends(user.CGetName(),user.CGetSurname());
}

const std::vector<User> SocialNetwork::CGetFriends(const std::string &name,
                                                   const std::string &surname) const {
  std::vector<User> ret{};

  /* YOUR CODE GOES HERE */
  size_t i= CUserIndex(name,surname);
  User u=User(name,surname);

  if (i!=friends.size()) {
      for (size_t j : friends[i])
          ret.push_back(users[j]);
  }
  return ret;
}

void SocialNetwork::AddFriendship(const std::string &first_name,
                                  const std::string &first_surname,
                                  const std::string &second_name,
                                  const std::string &second_surname) {

  /* YOUR CODE GOES HERE */
  size_t i= CUserIndex(first_name,first_surname);
  size_t j = CUserIndex(second_name,second_surname);

  if (i == j)
      return;
  if (i == users.size() || j == users.size())
      return;
  if (std::find(friends[i].begin(),friends[i].end(),j) != friends[i].end())
      return;

  friends[i].push_back(j);
  friends[j].push_back(i);
}

// debug: prints friends matrix
void SocialNetwork::print() {

        for (auto f:friends) {
            for(auto index:f){
                std::cout << index << " ";
            }
            std::cout << "\n";
        }
}

}
