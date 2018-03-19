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
        subTasks["${axisNodeValue}/${axisToolValue}/step1"] = {
            println "Node=${env.NODE_NAME}"
            println "Java=${axisToolValue}"
        }
        subTasks["${axisNodeValue}/${axisToolValue}/step2"] = {
            println "OK step2"
        }
    }
    tasks["${axisNodeValue}"] = {
        node() {
            subTasks
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