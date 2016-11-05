#include <random>
#include <cmath>
#include "BreakthroughMove.h"
#include "TranspositionTable.h"

void
TranspositionTable::insert(long zkey, BreakthroughMove move, int depth, int score, int min, int max) {
	TableEntry entry(zkey, move, depth, score, min, max);
	int index = (int)(zkey%TABLE_SIZE);
	table[index] = entry;
}

TableEntry&
TranspositionTable::lookup(long zkey) {
	int index = (int)(zkey%TABLE_SIZE);
	if (table[index].getKey() == zkey) {
		return table[index];
	}
}