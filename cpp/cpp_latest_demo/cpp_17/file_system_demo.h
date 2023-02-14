#pragma once

#include <filesystem>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
namespace fs = std::filesystem;

namespace cpp17::filesystem
{
	auto loop_dir()
	{
		fs::path pt("C:\\Windows");
		if (!fs::exists(pt)) {
			return 1;
		}
		fs::directory_entry entry(pt);
		if (entry.status().type() == fs::file_type::directory) {
			cout << "pt is a directory" << endl;
			fs::directory_iterator list(pt);
			for (auto& it : list) {
				if (!it.is_directory()) {
					cout << it.path().filename() << " "
						<< it.file_size() << " "
						<< endl;
				}
			}
		}
		return 0;
	}

	auto main()
	{
		cout << __FUNCTION__ << endl;
		loop_dir();

		string root{ "./cpp17_filesystem_demo/" };
		fs::create_directory(root);

		string fnm{ "file.txt" };
		ofstream fid(root + fnm);
		fid << "hello world" << endl;
		fid << 42 << endl;
		fid.close();
		auto ret = fs::exists(root + "file.txt");
		cout << ret << endl;
		fs::copy_file(root + fnm, root + "file.txt.bak", fs::copy_options::skip_existing);
		ret = fs::exists(root + "file.txt.bak");
		cout << ret << endl;
	}
}
