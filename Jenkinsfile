pipeline {
    agent any
    environment {
        CI = 'true'
    }
    stages {
        stage('Build') {
            steps {
                echo 'building...'
            }
        }
        stage('Test') {
            steps {
                echo 'testing...'
                sh './~/test.sh'
            }
        }
    }
}
