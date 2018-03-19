def axisNode = ["osx-agent-1","osx-agent-2"]
def axisTool = ["jdk7","jdk8"]
def tasks = [:]

stage("Before") {
    node {
        echo "before"
    }
}

for(int i=0; i< axisNode.size(); i++) {
    def axisNodeValue = axisNode[i]
    def subTasks = [:]
    for(int j=0; j< axisTool.size(); j++) {
        def axisToolValue = axisTool[j]
        subTasks["${axisNodeValue}/${axisToolValue}"] = {
            println "Node=${env.NODE_NAME}"
            println "Java=${axisToolValue}"
        }
    }
    tasks["${axisNodeValue}"] = {
        node() {
            parallel subTasks
        }
    }
}

stage ("Matrix") {
    parallel tasks
}

stage("After") {
    node {
        echo "after"
    }
}