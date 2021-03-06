#if defined _WIN32 || defined WIN32

#include "internal.h"

uint64_t cf_directory_exists(CC_String _path)
{
	CC_String path = cc_string_copy(_path);

	DWORD dwAttrib = GetFileAttributesA(path.data);

	cc_string_destroy(path);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES && (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

uint64_t cf_directory_create(CC_String path)
{
	char *c_path = malloc(path.length + 1);
	for (uint64_t i = 0; i < path.length; i++)
		c_path[i] = path.data[i];
	c_path[path.length] = '\0';

	uint64_t success = CreateDirectoryA(c_path, NULL);

	free(c_path);
	return success;
}

uint64_t cf_directory_destroy(CC_String path)
{
	char *c_path = malloc(path.length + 1);
	for (uint64_t i = 0; i < path.length; i++)
		c_path[i] = path.data[i];
	c_path[path.length] = '\0';

	uint64_t success = RemoveDirectoryA(c_path);

	free(c_path);
	return success;
}

#endif