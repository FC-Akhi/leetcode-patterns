struct nums_hash {
	int value;
	int idx;
	UT_hash_handle hh;
};

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
	struct nums_hash *table = NULL;
	struct nums_hash *entries = malloc(numsSize * sizeof(struct nums_hash));
	struct nums_hash *pos = entries;
	bool ret = false;
	for (int i = 0; i < numsSize && !ret; ++i) {
		struct nums_hash *entry;
		HASH_FIND_INT(table, &nums[i], entry);
		if (!entry) {
			entry = pos++;
			entry->value = nums[i];
			entry->idx = i;
			HASH_ADD_INT(table, value, entry);
		} else {
			if (entry->idx + k >= i) {
				ret = true;
			}
			entry->idx = i;
		}
	}

	HASH_CLEAR(hh, table);
	free(entries);

	return ret;
}