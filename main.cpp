#include <iostream>
#include <string>
#include <cstdio>

class Person {
public:
Person() = default;
Person(Person &copy)
{
	(this->parent)[0] = copy.parent[0];
	(this->parent)[1] = copy.parent[1];
	this->parent_count = copy.parent_count;
	this->name = copy.name;
	this->gene_type = copy.gene_type;
}

friend void add_data(std::string, std::string, Person *, int *);
friend bool compare_name(Person, Person);
bool check_parent();
void define_gene();
void print_data();
private:
class Person *parent[2]={0};
int parent_count = 0;
std::string name= "";
std::string gene_type= "";
};

void add_data(std::string input_name, std::string input_str, Person *data, int *data_count)
{

	if(input_str == "non-existent" || input_str == "recessive" || input_str == "dominant")
	{
		(data+(*data_count))->name = input_name;
		(data+(*data_count))->gene_type = input_str;
	}
	else
	{
		Person *buf;
		for(int i = 0; i <= *data_count; i++)               //find parent
		{
			if(data[i].name == input_name)
			{
				buf = data+i;
			}
		}

		for(int i = 0; i <= *data_count; i++)               //default the last one is empty
		{
			if(data[i].name == input_str || i == *data_count)
			{
				data[i].name = input_str;
				data[i].parent[data[i].parent_count] = buf;
				data[i].parent_count += 1;

				//std::cout << "Child is:" << data[i].name << " Parent is:"
				//          << (data[i].parent[data[i].parent_count-1])->name <<'\n';

				if(i != *data_count)
					return;
			}
		}
	}
	(*data_count) += 1;
}

bool Person::check_parent()
{
	return this->parent_count == 2 ? true : false;
}

void Person::define_gene()
{
	std::string pa_type=(this->parent)[0]->gene_type, ma_type=(this->parent)[1]->gene_type;

	//std::cout << "Define_gene:" << "pa_type:" << pa_type << " ma_type:" << ma_type << '\n';

	if(pa_type == "dominant" && ma_type == "dominant" || pa_type == "dominant" && ma_type == "recessive" || pa_type == "recessive" && ma_type == "dominant")
		this->gene_type = "dominant";
	else if(pa_type == "non-existent" && ma_type == "non-existent" || pa_type == "non-existent" && ma_type == "recessive" || pa_type == "recessive" && ma_type == "non-existent")
		this->gene_type = "non-existent";
	else
		this->gene_type = "recessive";
}

void Person::print_data()
{
	std::cout << this->name << " " << this->gene_type << '\n';
}

/*void Person::print_data() //debug version
   <<<<<<< HEAD
   {
        std::cout << "Name:" << this->name << '\n';
        std::cout << "Gene_type:" << this->gene_type << '\n';
        if((this->parent)[0] != nullptr && (this->parent)[1] != nullptr)
                std::cout << "Parent_name:" << (this->parent)[0]->name << ", " <<
                        (this->parent)[1]->name << "\n";
   }*/

bool compare_name(Person a, Person b)
{
	return a.name > b.name ? true : false;
}

int main(){

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	class Person data[3100];
	int data_num = 0, data_counter = 0; //num為總數，counter為目前數目
	std::cin >> data_num;

	for(int i = 0; i < data_num; i++)
	{
		std::string name, input_str;
		std::cin >> name >> input_str;
		add_data(name, input_str, &data[0], &data_counter);

		if(data[data_counter-1].check_parent())
			data[data_counter-1].define_gene();

	}


	for(int i = 0; i < data_counter; i++)
	{
		for(int j = 0; j < data_counter-1; j++)
		{
			if(compare_name(data[j], data[j+1]))
			{
				Person buf = data[j];
				data[j] = data[j+1];
				data[j+1] = buf;
			}
		}
	}

	for(int i = 1; i <= data_counter; i++) //print all data
	{
		data[i-1].print_data();
	}

	return 0;
}
