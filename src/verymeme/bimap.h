// Copyright 2019 E.
#ifndef VERYMEME_BIMAP_H_
#define VERYMEME_BIMAP_H_

#include <map>
#include <set>
#include <utility>

template <typename Key, typename Value>
class Bimap {
 public:
  bool containsKey(const Key& key) { return mapping.contains(key); }
  bool insert(const Key& key, const Value& val) {
    Record r{key, val};
    if (containsKey(key) || records.contains(r)) return false;
    auto res = records.emplace(std::move(r));
    mapping[key] = &res.first->v;
    return true;
  }
  const Key& keyForValue(const Value& val) {
    Record r{{}, val};
    return records.find(r)->k;
  }
  const Value& operator[](const Key& key) {
    bug_unless(mapping.contains(key));
    return *mapping[key];
  }

 private:
  struct Record {
    Key k;
    Value v;
    COMPARISON(Record, v);  // Just compare on Value so we can check if a value exists.
  };
  std::map<Key, const Value*> mapping;
  std::set<Record> records;
};

#endif  // VERYMEME_BIMAP_H_
