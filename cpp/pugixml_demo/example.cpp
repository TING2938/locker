#include "pugixml.hpp"

#include <iostream>

void access_modify_node()
{
    pugi::xml_document doc;

    // get a test document
    doc.load_string(R"(<project>
                            <name>test</name>
                            <version>1.1</version>
                            <public>yes</public>
                       </project>)");

    pugi::xml_node project = doc.child("project");

    // tag::access[]
    std::cout << "Project name: " << project.child("name").text().get() << std::endl;
    std::cout << "Project version: " << project.child("version").text().as_double() << std::endl;
    std::cout << "Project visibility: "
              << (project.child("public").text().as_bool(/* def= */ true) ? "public" : "private") << std::endl;
    std::cout << "Project description: " << project.child("description").text().get() << std::endl;
    // end::access[]

    std::cout << std::endl;

    // tag::modify[]
    // change project version
    project.child("version").text() = 1.2;

    // add description element and set the contents
    // note that we do not have to explicitly add the node_pcdata child
    project.append_child("description").text().set("a test project");
    // end::modify[]

    doc.save(std::cout);
}

void create_node()
{
    pugi::xml_document doc;

    // tag::code[]
    // add node with some name
    pugi::xml_node node = doc.append_child("node");

    // add description node with text child
    pugi::xml_node descr = node.append_child("description");
    descr.append_child(pugi::node_pcdata).set_value("Simple node");

    // add param node before the description
    pugi::xml_node param = node.insert_child_before("param", descr);

    // add attributes to param node
    param.append_attribute("name")                                = "version";
    param.append_attribute("value")                               = 1.1;
    param.insert_attribute_after("type", param.attribute("name")) = "float";
    // end::code[]

    doc.print(std::cout);
}

int main()
{
    access_modify_node();
    create_node();
}
