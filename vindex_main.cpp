#include <iostream>

#include "leveldb/db.h"

int main() {
  leveldb::DB* db;

  leveldb::Options options;
  options.create_if_missing = true;

  leveldb::Status status = leveldb::DB::Open(options, "./testdb", &db);
  if (!status.ok()) {
    std::cerr << "Unable to create / open the database";
    return EXIT_FAILURE;
  }

  leveldb::WriteOptions writeOptions;
  db->Put(writeOptions, "key1", "val1");

  // Iterate over each item in the database and print them
  leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());

  for (it->SeekToFirst(); it->Valid(); it->Next()) {
    std::cout << it->key().ToString() << " : " << it->value().ToString()
              << std::endl;
  }

  return EXIT_SUCCESS;
}
