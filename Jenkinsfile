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
            when {
                branch 'jenkins_file'
            }
            steps {
                echo 'testing...'
                sh '~/test.sh'
            }
        }
        stage('Test-master') {
            when {
                branch 'master'
            }
            steps {
                echo 'testing...'
                sh '~/test.sh'
            }
        }
    }
}
