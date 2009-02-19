/**
 *	fuse_impl.h
 *
 *	@author	Masaki Fujimoto <fujimoto@php.net>
 *
 *	$Id$
 */
#ifndef	__FUSE_IMPL_H__
#define	__FUSE_IMPL_H__

#define	FUSE_USE_VERSION	25
#include <fuse.h>

#include "flarefs.h"

namespace gree {
namespace flare {

/**
 *	fuse implementation class for flarefs
 */
class fuse_impl {
private:
	bool				_allow_other;
	bool				_allow_root;
	string			_mount_dir;
	string			_node_server_name;
	int					_node_server_port;

public:
	fuse_impl(string mount_dir, string node_server_name, int node_server_port);
	~fuse_impl();

	int run();

	int set_allow_other(bool flag) { this->_allow_other = flag; return 0; };
	int set_allow_root(bool flag) { this->_allow_root = flag; return 0; };

	int getattr(const char* path, struct stat* st);
	int readlink(const char* src_path, char* dst_path, size_t dst_path_size);
	int mknod(const char* path, mode_t m, dev_t d);
	int mkdir(const char* path, mode_t m);
	int unlink(const char* path);
	int rmdir(const char* path);
	int symlink(const char* src_path, const char* dst_path);
	int rename(const char* src_path, const char* dst_path);
	int link(const char* src_path, const char* dst_path);
	int chmod(const char* path, mode_t m);
	int chown(const char* path, uid_t u, gid_t g);
	int truncate(const char* path, off_t o);
	int utime(const char* path, struct utimbuf* u);
	int open(const char* path, struct fuse_file_info* f);
	int read(const char* path, char* buf, size_t buf_size, off_t o, struct fuse_file_info* f);
	int write(const char* path, const char* buf, size_t buf_size, off_t o, struct fuse_file_info* f);
	int statfs(const char* path, struct statvfs* st);
	int flush(const char* path, struct fuse_file_info* f);
	int release(const char* path, struct fuse_file_info* f);
	int fsync(const char* path, int m, struct fuse_file_info* f);
	int setxattr(const char* path, const char* name, const char* value, size_t value_size, int m); 
	int getxattr(const char* path, const char* name, char* value, size_t value_size);
	int listxattr(const char* path, char* buf, size_t buf_size);
	int removexattr(const char* path, const char* name);
	int opendir(const char* path, struct fuse_file_info* f);
	int readdir(const char* path, void* buf, fuse_fill_dir_t d, off_t o, struct fuse_file_info* f);
	int fsyncdir(const char* path, int m, struct fuse_file_info* f);
	void* init();
	void destroy(void* buf);
	int access(const char* path, int m);
	int create(const char* path, mode_t m, struct fuse_file_info* f);
	int ftruncate(const char* path, off_t o, struct fuse_file_info* f) ;
	int fgetattr(const char* path, struct stat* st, struct fuse_file_info* f);

protected:

private:
};

}	// namespace flare
}	// namespace gree

#endif	// __FUSE_IMPL_H__
// vim: foldmethod=marker tabstop=2 shiftwidth=2 autoindent
