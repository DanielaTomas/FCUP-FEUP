import numpy as np

from math import sin, cos, pi



from scipy.integrate import ode

from scipy.optimize import fsolve

from scipy.spatial import ConvexHull



from abc import ABC, abstractmethod



import matplotlib.pyplot as plt

from matplotlib.patches import Ellipse as EllipsePlot

from matplotlib.path import Path



class DynamicSystem(ABC):

    '''

    Abstract class for dynamic systems. This class has all the functionality for simulating dynamic systems using scipy integration methods.

    The abstract functionality that needs to be implemented by the child classes is the flow computation.

    '''

    def __init__(self, initial_state, initial_control):

        

        # Sets integration method from scipy

        self.mODE = ode(self.get_flow).set_integrator('dopri5')

        self.set_state(initial_state)

        self.set_control(initial_control)



        self.state_log = []

        for _ in range(0, self.n):

            self.state_log.append([])



        self.control_log = []

        for _ in range(0, self.m):

            self.control_log.append([])



    def set_state(self, state):

        '''

        Sets system state.

        '''

        self.n = len(state)

        self._state = np.array(state)

        self._dstate = np.zeros(self.n)

        self.mODE.set_initial_value(self._state)



    def set_control(self, control_input):

        '''

        Sets system control.

        '''

        self.m = len(control_input)

        self._control = np.array(control_input)



    def actuate(self, dt):

        '''

        Sends the control inputs.

        '''

        self.dynamics()

        self._state = self.mODE.integrate(self.mODE.t+dt)



        for state_dim in range(0, self.n):

            self.state_log[state_dim].append(self._state[state_dim])



        for ctrl_dim in range(0, self.m):

            self.control_log[ctrl_dim].append(self._control[ctrl_dim])



    def get_flow(self, t):

        '''

        Gets the current system flow, or state derivative.

        '''

        return self._dstate



    def get_state(self):

        '''

        Gets the current system state.

        '''

        return self._state



    def get_control(self):

        '''

        Gets the last control input.

        '''

        return self._control



    @abstractmethod

    def dynamics(self):

        pass





class AffineSystem(DynamicSystem):

    '''

    General class for an affine system dx = f(x) + g(x) u.

    '''

    def __init__(self, initial_state, initial_control):

        super().__init__(initial_state, initial_control)

        self._f = np.zeros(self.n)

        self._g = np.zeros([self.n, self.m])



    def get_f(self):

        '''

        Gets the value of f(x).

        '''

        return self._f



    def get_g(self):

        '''

        Gets the value of g(x).

        '''

        return self._g



    def dynamics(self):

        '''

        General affine system dynamics.

        '''

        self.f()

        self.g()

        self._dstate = self._f + self._g @ self._control



    @abstractmethod

    def f(self):

        pass



    @abstractmethod

    def g(self):

        pass





class Integrator(AffineSystem):

    '''

    Implements a simple n-order integrator.

    '''

    def __init__(self, initial_state, initial_control):

        if len(initial_state) != len(initial_control):

            raise Exception('Number of inputs is different than the number of states.')

        super().__init__(initial_state, initial_control)

        self.f()

        self.g()



    def f(self):

        self._f = np.zeros(self.n)



    def g(self):

        self._g = np.eye(self.n)





class LinearSystem(AffineSystem):

    '''

    Implements a linear system dx = A x + B u.

    '''

    def __init__(self, initial_state, initial_control, A, B):

        super().__init__(initial_state, initial_control)

        self._A = A

        self._B = B



    def f(self):

        self._f = self._A @ self._state



    def g(self):

        self._g = self._B





class Unicycle(AffineSystem):

    '''

    Implements the unicycle dynamics: dx = v cos(phi), dy = v sin(phi), dphi = omega.

    State and control are given by [x, y, z] and [v, omega], respectively.

    '''

    def __init__(self, initial_state, initial_control):

        if len(initial_state) != 3:

            raise Exception('State dimension is different from 3.')

        if len(initial_control) != 2:

            raise Exception('Control dimension is different from 3.')

        super().__init__(initial_state, initial_control)

        self.f()

        self.g()



    def f(self):

        self._f = np.zeros(self.n)



    def g(self):

        x = self._state[0]

        y = self._state[1]

        phi = self._state[2]

        self._g = np.array([[ np.cos(phi), 0.0 ],[ np.sin(phi), 0.0 ],[0.0, 1.0]])





class Ellipse():

    '''

    Implementation of elliptical obstacle class.

    '''

    def __init__(self, center = [0.0, 0.0], angle = 0.0, axes = [1.0, 1.0]):

        self.center = np.array(center)

        self.angle = angle

        self.axes = np.array(axes)

        self.point = np.zeros(2)



        s = np.sin(self.angle)

        c = np.cos(self.angle)

        self.R = np.array([[c,s],[-s,c]])



    def equations(self, vars):

        '''

        Equation for solving the 'nearest point to ellipse' problem. 

        '''

        l, gamma = vars



        a = self.axes[0]

        b = self.axes[1]



        term = self.R @ ( self.point - self.center )

        eq1 = (a + l*b)*cos(gamma) - term[0]

        eq2 = (b + l*a)*sin(gamma) - term[1]



        return [eq1, eq2]



    def compute_closest(self, point):

        '''

        Computes the closest point on the ellipse with respect to a given point.

        '''

        if self.isInside(point):

            return point, 0.0



        self.point = np.array(point)

        initial_l = np.random.rand()

        initial_gamma = pi*np.random.rand()

        l_sol, gamma_sol = fsolve(self.equations, (initial_l,initial_gamma))

        while l_sol < 0:

            initial_l = np.random.rand()

            initial_gamma = pi*np.random.rand()

            l_sol, gamma_sol = fsolve(self.equations, (initial_l, initial_gamma))



        a = self.axes[0]

        b = self.axes[1]



        v = np.array([ a*cos(gamma_sol), b*sin(gamma_sol) ])

        n = np.array([ b*cos(gamma_sol), a*sin(gamma_sol) ])

        closest_point = self.R.T @ v + self.center

        # distance = l_sol*np.linalg.norm(n)

        distance = np.linalg.norm(closest_point - point)



        return closest_point, distance



    def plot(self):

        ellipse = EllipsePlot(self.center, 2*self.axes[0], 2*self.axes[1], angle=np.degrees(self.angle), color='g', label='obstacle')

        plt.gca().add_patch(ellipse)



    def isInside(self, point):

        '''

        Checks if point is inside of ellipse.

        '''

        a = self.axes[0]

        b = self.axes[1]

        v = self.R @ ( np.array(point) - self.center )

        Lambda = np.diag([ 1/a**2, 1/b**2 ])

        expr = v.T @ Lambda @ v - 1



        return expr < 0





class Line():

    '''

    Implementation of simple line.

    '''

    def __init__(self, p1 = [0.0, 0.0], p2 = [1.0, 1.0]):

        self.p1 = np.array(p1)

        self.p2 = np.array(p2)

        self.line_vector = self.p2 - self.p1

        self.angle = np.arctan2( self.line_vector[1], self.line_vector[0] )

        self.normal = np.array([ -sin(self.angle), cos(self.angle) ])



        self.point = np.zeros(2)



    def equations(self, vars):

        '''

        Equation for solving the 'nearest point to wall' problem. 

        '''

        l, gamma = vars



        eq1 = self.p1[0]*(1-gamma) + self.p2[0]*gamma + l*self.normal[0] - self.point[0]

        eq2 = self.p1[1]*(1-gamma) + self.p2[1]*gamma + l*self.normal[1] - self.point[1]



        return [eq1, eq2]



    def compute_closest(self, point):

        '''

        Computes the closest point on the line with respect to a given point.

        '''

        self.point = np.array(point)

        initial_l = np.random.rand()

        initial_gamma = np.random.rand()

        l_sol, gamma_sol = fsolve(self.equations, (initial_l,initial_gamma))

        distance = np.abs(l_sol)



        if gamma_sol > 1:

            gamma_sol = 1

            distance = np.linalg.norm( self.point - self.p2 )

        elif gamma_sol < 0:

            gamma_sol = 0

            distance = np.linalg.norm( self.point - self.p1 )



        closest_point = self.p1*(1-gamma_sol) + self.p2*gamma_sol



        return closest_point, distance



    def plot(self):

        '''

        Plot line.

        '''

        plt.plot(self.p1[0], self.p1[1], color='r', marker='*')

        plt.plot(self.p2[0], self.p2[1], color='r', marker='*')

        plt.plot([self.p1[0],self.p2[0]], [self.p1[1],self.p2[1]], color='b', linewidth=2.0)





class ConvexPolygon():

    '''

    Implementation of a convex polygon class. Vertices must be the vertices of a convex polygon.

    '''

    def __init__(self, vertices):

        self.vertices = np.array(vertices)

        self.num_vertices = len(self.vertices)

        self.lines = []



        self.create_lines()



        self.hull = ConvexHull( self.vertices )

        self.hull_path = Path( self.vertices[self.hull.vertices] )



    def create_lines(self):

        '''

        Create lines from vertice points.

        '''

        for k in range(self.num_vertices-1):

            self.lines.append( Line(p1 = self.vertices[k,:], p2 = self.vertices[k+1,:]) )

        self.lines.append( Line(p1 = self.vertices[-1,:], p2 = self.vertices[0,:]) )



    def isInside(self, point):

        '''

        Checks whether the point is inside the ConvexPolygon or not.

        '''

        return self.hull_path.contains_point(point)



    def compute_closest(self, point):

        '''

        Computes the closest point on the polygon to point.

        '''

        if self.isInside(point):

            return point, 0.0



        num_lines = len(self.lines)

        line_distances = np.zeros(num_lines)

        line_pts = np.zeros([2,num_lines])

        for k in range(num_lines):

            line_pts[:,k], line_distances[k] = self.lines[k].compute_closest(point)

        closest_line_index = np.argmin(line_distances)

        closest_line_pt = line_pts[:,closest_line_index]

        closest_line_dist = line_distances[closest_line_index]



        return closest_line_pt, closest_line_dist



    def plot(self):

        '''

        Plot polygon.

        '''

        for line in self.lines:

            line.plot()



class World():

    '''

    Implementation of simple class for a world with a polygonal arena and obstacles (elliptical and polygonal)

    '''

    def __init__(self, arena):

        self.arena = arena

        self.obstacles = []

        self.closest_object = None



    def add_obstacle(self, obs):

        '''

        Adds obstacles to the simulated world.

        '''

        self.obstacles.append(obs)



    def compute_closest(self, point):

        '''

        Computes the closest point on the obstacles or walls, with respect to point.

        '''

        # First, checks the arena walls

        closest_wall_dist = float('inf')

        num_walls = len(self.arena.lines)

        if num_walls > 0:

            wall_distances = np.zeros(num_walls)

            wall_pts = np.zeros([2,num_walls])

            for k in range(num_walls):

                wall_pts[:,k], wall_distances[k] = self.arena.lines[k].compute_closest(point)

            closest_wall_index = np.argmin(wall_distances)

            closest_wall_pt = wall_pts[:,closest_wall_index]

            closest_wall_dist = wall_distances[closest_wall_index]



        # Then, checks the obstacles

        closest_obs_dist = float('inf')

        num_obs = len(self.obstacles)

        if num_obs > 0:

            obs_distances = np.zeros(num_obs)

            obs_pts = np.zeros([2,num_obs])

            for k in range(num_obs):

                obs_pts[:,k], obs_distances[k] = self.obstacles[k].compute_closest(point)

            closest_obs_index = np.argmin(obs_distances)

            closest_obs_pt = obs_pts[:,closest_obs_index]

            closest_obs_dist = obs_distances[closest_obs_index]



        if closest_obs_dist < closest_wall_dist:

            closest_pt = closest_obs_pt

            closest_dist = closest_obs_dist

            self.closest_obstacle = self.obstacles[closest_obs_index]

        else:

            closest_pt = closest_wall_pt

            closest_dist = closest_wall_dist

            self.closest_obstacle = self.arena.lines[closest_wall_index]



        return closest_pt, closest_dist



    def plot(self):

        '''

        Plot the whole world.

        '''

        self.arena.plot()

        for obs in self.obstacles:

            obs.plot()





    

def check_collisions(points_vec, d_mtx, w_R_mtx, do, xi, time_score):



    #c_mtx = d_mtx

    

#    for i in range(0,len(points_vec)-1):
    for i in range(0,len(points_vec)):



        if d_mtx[i]==0: 

            if points_vec[i][0] > 10 or points_vec[i][0] < -10 or points_vec[i][1] > 10 or points_vec[i][1] < -10: # Verify if the drone left the arena

                d_mtx[i]=1

                print('WARNING: Drone', i+1, 'left the arena!!')

                if w_R_mtx[i] == 1:

                    w_R_mtx[i] = 0

                    ind = np.where(w_R_mtx == 1)

                    ind_eli = ind[0][0]

                    w_R_mtx[ind_eli] = 0

                elif w_R_mtx[i] == 2:

                    w_R_mtx[i] = 0

                    ind2 = np.where(w_R_mtx == 1)

                    ind_eli2 = ind2[0][0]

                    w_R_mtx[ind_eli2] = 0

                continue



            elif do[i] < 0.01: # If distance to nearest object is smaller than 0.01, the drone is damaged

                d_mtx[i]=1

                print('WARNING: Collision with obstacle! Drone:', i+1)

                if w_R_mtx[i] == 1:

                    w_R_mtx[i] = 0

                    ind = np.where(w_R_mtx == 1)

                    ind_eli = ind[0][0]

                    w_R_mtx[ind_eli] = 0

                elif w_R_mtx[i] == 2:

                    w_R_mtx[i] = 0

                    ind2 = np.where(w_R_mtx == 1)

                    ind_eli2 = ind2[0][0]

                    w_R_mtx[ind_eli2] = 0

                continue

            

            # Verify collisions between drones

            for j in range(i+1,4): 

                dist = np.sqrt( (points_vec[i][0] - points_vec[j][0])**2 + (points_vec[i][1] - points_vec[j][1])**2 ) 

                if dist < 0.1: 

                    d_mtx[i]=1

                    d_mtx[j]=1

                    print('WARNING: Colision between drone', i+1, 'and drone', j+1,'!!', ' -> dist =', dist)

                    if w_R_mtx[j] == 1:

                        w_R_mtx[j] = 0

                        ind = np.where(w_R_mtx == 1)

                        ind_eli = ind[0][0]

                        w_R_mtx[ind_eli] = 0

                        time_score[0] = 999.9

                        print('WARNING: Resource 1 lost!')



                    if w_R_mtx[i] == 1:

                        w_R_mtx[i] = 0

                        ind = np.where(w_R_mtx == 1)

                        ind_eli = ind[0][0]

                        w_R_mtx[ind_eli] = 0

                        time_score[0] = 999.9

                        print('WARNING: Resource 1 lost!')



                    if w_R_mtx[j] == 2:

                        w_R_mtx[j] = 0

                        ind2 = np.where(w_R_mtx == 2)

                        ind_eli2 = ind2[0][0]

                        w_R_mtx[ind_eli2] = 0

                        time_score[1] = 999.9

                        print('WARNING: Resource 2 lost!')



                    if w_R_mtx[i] == 2:

                        w_R_mtx[i] = 0

                        ind2 = np.where(w_R_mtx == 2)

                        ind_eli2 = ind2[0][0]

                        w_R_mtx[ind_eli2] = 0

                        time_score[1] = 999.9

                        print('WARNING: Resource 2 lost!')



                 

    #d_mtx = c_mtx

    

    return d_mtx, w_R_mtx, time_score

    





# xi_all = (xi21, xi23, xi24, xi25, xi31, xi32, xi34, xi35, xi41, xi42, xi43, xi45, xi51, xi52, xi53, xi54)

def update_relat_position(position_mtx, xi_all, max_distance):

    pos = 0

    # Dist from 2

    if np.linalg.norm(xi_all[0]) > max_distance : # Dist from 2 - 1

        position_mtx[1][pos] = 0

        position_mtx[pos][1] = 0

        xi_all[0][0] = 0

        xi_all[0][1] = 0

    else:

        position_mtx[1][pos] = 1

        position_mtx[pos][1] = 1

    

    pos = 2

    if np.linalg.norm(xi_all[1]) > max_distance : # Dist from 2 - 3

        position_mtx[1][pos] = 0

        position_mtx[pos][1] = 0

        xi_all[1][0] = 0

        xi_all[1][1] = 0

    else:

        position_mtx[1][pos] = 1

        position_mtx[pos][1] = 1

    

    pos = 3

    if np.linalg.norm(xi_all[2]) > max_distance : # Dist from 2 - 4

        position_mtx[1][pos] = 0

        position_mtx[pos][1] = 0

        xi_all[2][0] = 0

        xi_all[2][1] = 0

    else:

        position_mtx[1][pos] = 1

        position_mtx[pos][1] = 1

    

    pos = 4

    if np.linalg.norm(xi_all[3]) > max_distance : # Dist from 2 - 5

        position_mtx[1][pos] = 0

        position_mtx[pos][1] = 0

        xi_all[3][0] = 0

        xi_all[3][1] = 0

    else:

        position_mtx[1][pos] = 1

        position_mtx[pos][1] = 1

    

    pos = 0

    # Dist from 3

    if np.linalg.norm(xi_all[4]) > max_distance : # Dist from 3 - 1

        position_mtx[2][pos] = 0

        position_mtx[pos][2] = 0

        xi_all[4][0] = 0

        xi_all[4][1] = 0

    else:

        position_mtx[2][pos] = 1

        position_mtx[pos][2] = 1

    

    pos = 1

    if np.linalg.norm(xi_all[5]) > max_distance : # Dist from 3 - 2

        position_mtx[2][pos] = 0

        position_mtx[pos][2] = 0

        xi_all[5][0] = 0

        xi_all[5][1] = 0

    else:

        position_mtx[2][pos] = 1

        position_mtx[pos][2] = 1

    

    pos = 3

    if np.linalg.norm(xi_all[6]) > max_distance : # Dist from 3 - 4

        position_mtx[2][pos] = 0

        position_mtx[pos][2] = 0

        xi_all[6][0] = 0

        xi_all[6][1] = 0

    else:

        position_mtx[2][pos] = 1

        position_mtx[pos][2] = 1

    

    pos = 4

    if np.linalg.norm(xi_all[7]) > max_distance : # Dist from 3 - 5

        position_mtx[2][pos] = 0

        position_mtx[pos][2] = 0

        xi_all[7][0] = 0

        xi_all[7][1] = 0

    else:

        position_mtx[2][pos] = 1

        position_mtx[pos][2] = 1

    

    pos = 0

    # Dist from 4

    if np.linalg.norm(xi_all[8]) > max_distance : # Dist from 4 - 1

        position_mtx[3][pos] = 0

        position_mtx[pos][3] = 0

        xi_all[8][0] = 0

        xi_all[8][1] = 0

    else:

        position_mtx[3][pos] = 1

        position_mtx[pos][3] = 1

    

    pos = 1

    if np.linalg.norm(xi_all[9]) > max_distance : # Dist from 4 - 2

        position_mtx[3][pos] = 0

        position_mtx[pos][3] = 0

        xi_all[9][0] = 0

        xi_all[9][1] = 0

    else:

        position_mtx[3][pos] = 1

        position_mtx[pos][3] = 1

    

    pos = 2

    if np.linalg.norm(xi_all[10]) > max_distance : # Dist from 4 - 3

        position_mtx[3][pos] = 0

        position_mtx[pos][3] = 0

        xi_all[10][0] = 0

        xi_all[10][1] = 0

    else:

        position_mtx[2][pos] = 1

        position_mtx[pos][2] = 1

    

    pos = 4

    if np.linalg.norm(xi_all[11]) > max_distance : # Dist from 4 - 5

        position_mtx[3][pos] = 0

        position_mtx[pos][3] = 0

        xi_all[11][0] = 0

        xi_all[11][1] = 0

    else:

        position_mtx[3][pos] = 1

        position_mtx[pos][3] = 1

    

    pos = 0

    # Dist from 5

    if np.linalg.norm(xi_all[12]) > max_distance : # Dist from 5 - 1

        position_mtx[4][pos] = 0

        position_mtx[pos][4] = 0

        xi_all[12][0] = 0

        xi_all[12][1] = 0

    else:

        position_mtx[4][pos] = 1

        position_mtx[pos][4] = 1

    

    pos = 1

    if np.linalg.norm(xi_all[13]) > max_distance : # Dist from 5 - 2

        position_mtx[4][pos] = 0

        position_mtx[pos][4] = 0

        xi_all[13][0] = 0

        xi_all[13][1] = 0

    else:

        position_mtx[4][pos] = 1

        position_mtx[pos][4] = 1

    

    pos = 2

    if np.linalg.norm(xi_all[14]) > max_distance : # Dist from 5 - 3

        position_mtx[4][pos] = 0

        position_mtx[pos][4] = 0

        xi_all[14][0] = 0

        xi_all[14][1] = 0

    else:

        position_mtx[4][pos] = 1

        position_mtx[pos][4] = 1

    

    pos = 3

    if np.linalg.norm(xi_all[15]) > max_distance : # Dist from 5 - 4

        position_mtx[4][pos] = 0

        position_mtx[pos][4] = 0

        xi_all[15][0] = 0

        xi_all[15][1] = 0

    else:

        position_mtx[4][pos] = 1

        position_mtx[pos][4] = 1
        
        
        

    pos = 1

    # Dist from 1

    if np.linalg.norm(xi_all[16]) > max_distance : # Dist from 1 - 2

        position_mtx[0][pos] = 0

        position_mtx[pos][0] = 0

        xi_all[16][0] = 0

        xi_all[16][1] = 0

    else:

        position_mtx[0][pos] = 1

        position_mtx[pos][0] = 1

    

    pos = 2

    if np.linalg.norm(xi_all[17]) > max_distance : # Dist from 1 - 3

        position_mtx[0][pos] = 0

        position_mtx[pos][0] = 0

        xi_all[17][0] = 0

        xi_all[17][1] = 0

    else:

        position_mtx[0][pos] = 1

        position_mtx[pos][0] = 1

    

    pos = 3

    if np.linalg.norm(xi_all[18]) > max_distance : # Dist from 1 - 4

        position_mtx[0][pos] = 0

        position_mtx[pos][0] = 0

        xi_all[18][0] = 0

        xi_all[18][1] = 0

    else:

        position_mtx[0][pos] = 1

        position_mtx[pos][0] = 1

    

    pos = 4

    if np.linalg.norm(xi_all[19]) > max_distance : # Dist from 1 - 5

        position_mtx[0][pos] = 0

        position_mtx[pos][0] = 0

        xi_all[19][0] = 0

        xi_all[19][1] = 0

    else:

        position_mtx[0][pos] = 1

        position_mtx[pos][0] = 1

    return position_mtx, xi_all





def proximity(points_vec, resource, num_R):



    prox_mtx_1 = np.array([np.sqrt((points_vec[0][0] - resource[1][0])**2 + (points_vec[0][1] - resource[1][1])**2), 

                        np.sqrt((points_vec[1][0] - resource[1][0])**2 + (points_vec[1][1] - resource[1][1])**2),

                        np.sqrt((points_vec[2][0] - resource[1][0])**2 + (points_vec[2][1] - resource[1][1])**2),

                        np.sqrt((points_vec[3][0] - resource[1][0])**2 + (points_vec[3][1] - resource[1][1])**2),

                        np.sqrt((points_vec[4][0] - resource[1][0])**2 + (points_vec[4][1] - resource[1][1])**2)])

    if num_R == 2:

        prox_mtx_2 = np.array([np.sqrt((points_vec[0][0] - resource[2][0])**2 + (points_vec[0][1] - resource[2][1])**2),

                            np.sqrt((points_vec[1][0] - resource[2][0])**2 + (points_vec[1][1] - resource[2][1])**2),

                            np.sqrt((points_vec[2][0] - resource[2][0])**2 + (points_vec[2][1] - resource[2][1])**2),

                            np.sqrt((points_vec[3][0] - resource[2][0])**2 + (points_vec[3][1] - resource[2][1])**2),

                            np.sqrt((points_vec[4][0] - resource[2][0])**2 + (points_vec[4][1] - resource[2][1])**2)])

    else:

        prox_mtx_2 = np.array([999.9,999.9,999.9,999.9,999.9])





    return prox_mtx_1, prox_mtx_2

    

    

    

def closest_drones(prox_mtx_1, prox_mtx_2, w_R_mtx, time_score, t, R_delivered, num_R, dist_R):

    # Find the closest drones to the Resource

    closer = 99

    pre_candidate = 9

    candidate = 9


            

    for i in range(0, 5):

        if prox_mtx_1[i] < closer and w_R_mtx[i] == 0: # Finds the closest drone without Resource        

            closer = prox_mtx_1[i]

            pre_candidate = i

    

    closer = 99



    if pre_candidate != 9: # If a drone withou Resource was found and is the closest

        if prox_mtx_1[pre_candidate] < dist_R and not 1 in w_R_mtx and R_delivered[0] == 0: # If distance to the Resource is smaller than dist_R and Resource 1 is not delivered and isn't with any other drone

            print('Drone',pre_candidate+1,'found the Resource 1')

            

            for i in range(0,5):

                if i != pre_candidate and w_R_mtx[i] == 0: # Verifies all drones except the closest one, and the ones with Resource

                    if prox_mtx_1[i] < dist_R and prox_mtx_1[i] < closer: # If closer than dist_R, closer than closer (to get the minimum) and without Resource

                        closer = prox_mtx_1[i]

                        candidate = i

            if candidate != 9:

                print('Drone',candidate+1,'found the Resource 1')

                w_R_mtx[pre_candidate] = 1

                w_R_mtx[candidate] = 1

                time_score[0] = t

            else:

                print('But no other drone found the Resource 1...')

    

    if num_R == 2:  

        closer = 99

        pre_candidate = 9

        candidate = 9

        

        for i in range(0, 5):

            if prox_mtx_2[i] < closer and w_R_mtx[i] == 0: # Finds the closest drone without Resource   

                closer = prox_mtx_1[i]

                pre_candidate = i



        closer = 99

        

        if pre_candidate != 9: # If a drone withou Resource was found and is the closest

            if prox_mtx_2[(pre_candidate)] < dist_R and not 2 in w_R_mtx and R_delivered[1] == 0: # If distance to the Resource is smaller than dist_R and Resource 1 is not delivered and isn't with any other drone

                print('Drone',pre_candidate+1,'found the Resource 2')

                for i in [x for x in range(0,5) if x != pre_candidate and w_R_mtx[x] == 0]: # Verifies all drones except the closest one, and the ones with Resource

                    if prox_mtx_2[i] < dist_R and prox_mtx_2[i] < closer and w_R_mtx[i] == 0: # If closer than Resource, closer than closer (to get the minimum) and without Resource

                        closer = prox_mtx_2[i]

                        candidate = i

                if candidate != 9:

                    print('Drone',candidate+1,'found the Resource 2')

                    w_R_mtx[pre_candidate] = 2

                    w_R_mtx[candidate] = 2

                    time_score[1] = t

                else:

                    print('But no other drone found the Resource 2...')



    return w_R_mtx, time_score







def R_warehouse_check(w_R_mtx, points_vec, Resource, time_score, t, R_delivered, d_max):

    # Verify if Resource reached base or lost Resource

    if 1 in w_R_mtx:    

        result = np.where(w_R_mtx == 1)

        index = result[0][0]

        index_2 = result[0][1]



        if points_vec[index][0] < -5 and points_vec[index][1] < -5 and points_vec[index_2][0] < -5 and points_vec[index_2][1] < -5: # Arriving to base

            Resource[1][0] = points_vec[index][0]

            Resource[1][1] = points_vec[index][1]

            time_score[2] = t

            w_R_mtx[index] = 0

            w_R_mtx[index_2] = 0

            R_delivered[0] = 1

            print('Resource 1 delivered!')

        elif np.sqrt( (points_vec[index][0] - points_vec[index_2][0])**2 + (points_vec[index][1] - points_vec[index_2][1])**2 ) > d_max: #1.5: # Loosing Resource

            w_R_mtx[index] = 0

            w_R_mtx[index_2] = 0

            time_score [0] = 999.9 

            print('WARNING: Resource 1 lost!')



    if 2 in w_R_mtx:

        result2 = np.where(w_R_mtx == 2)

        index2 = result2[0][0]

        index2_2 = result2[0][1]



        if points_vec[index2][0] < -5 and points_vec[index2][1] < -5 and points_vec[index2_2][0] < -5 and points_vec[index2_2][1] < -5: # Arriving to base

            Resource[2][0] = points_vec[index2][0]

            Resource[2][1] = points_vec[index2][1]

            time_score[3] = t

            w_R_mtx[index2] = 0

            w_R_mtx[index2_2] = 0

            R_delivered[1] = 1

            print('Resource 2 delivered!')

        elif np.sqrt( (points_vec[index2][0] - points_vec[index2_2][0])**2 + (points_vec[index2][1] - points_vec[index2_2][1])**2 ) > d_max: #1.5: # Loosing Resource

            w_R_mtx[index2] = 0

            w_R_mtx[index2_2] = 0

            time_score [1] = 999.9 

            print('WARNING: Resource 2 lost!')

    

    return w_R_mtx, time_score, R_delivered